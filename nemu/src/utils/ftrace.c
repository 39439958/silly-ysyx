#include <common.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <debug.h>

typedef struct {
    char name[32];
    paddr_t addr;
    unsigned char info;
    Elf32_Xword size;
} symbol_table;

symbol_table *symbol_tables = NULL;
int symbol_tables_size = 0;

/**
 * 解析elf文件并存入symbol_tables
*/
void parse_elf(const char *elf_file) {
    if (elf_file == NULL)
        return;
    // 打开ELF文件
    FILE *fp = fopen(elf_file, "rb");
    Assert(fp, "Can not open '%s'", elf_file);

    // 读取ELF header
    Elf32_Ehdr elf_header;
    if (fread(&elf_header, sizeof(Elf32_Ehdr), 1, fp) <= 0) {
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 检查文件是否为ELF文件
    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not an ELF file\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 移动到Section header table,寻找字符表节
    fseek(fp, elf_header.e_shoff, SEEK_SET);
    Elf32_Shdr strtab_header;
    while (1) {
        if (fread(&strtab_header, sizeof(Elf32_Shdr), 1, fp) <= 0) {
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        if (strtab_header.sh_type == SHT_STRTAB) {
            break;
        }
    }

    // 读取字符串表内容
    char *string_table = malloc(strtab_header.sh_size);
    fseek(fp, strtab_header.sh_offset, SEEK_SET);
    if (fread(string_table, strtab_header.sh_size, 1, fp) <= 0) {
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 寻找符号表节
    Elf32_Shdr symtab_header;
    fseek(fp, elf_header.e_shoff, SEEK_SET);
    while (1) {
        if (fread(&symtab_header, sizeof(Elf32_Shdr), 1, fp) <= 0) {
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        if (symtab_header.sh_type == SHT_SYMTAB) {
            break;
        }
    }

    /* 读取符号表中的每个符号项 */ 

    fseek(fp, symtab_header.sh_offset, SEEK_SET);
    Elf32_Sym symbol;
    // 确定符号表的条数
    size_t num_symbols = symtab_header.sh_size / symtab_header.sh_entsize;
    // 分配内存用于存储符号表
    symbol_tables = malloc(num_symbols * sizeof(symbol_table));

    for (size_t i = 0; i < num_symbols; ++i) {
        if (fread(&symbol, sizeof(Elf32_Sym), 1, fp) <= 0 ) {
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        // 判断符号是否为函数，并且函数的大小不为零
        if (ELF64_ST_TYPE(symbol.st_info) == STT_FUNC && symbol.st_size != 0) {
            // 从字符串表中获取符号名称
            const char *name = string_table  + symbol.st_name;
            // 存储符号信息到 symbol_table 结构体数组
            strncpy(symbol_tables[i].name, name, sizeof(symbol_tables[i].name) - 1);
            symbol_tables[i].addr = symbol.st_value;
            symbol_tables[i].info = symbol.st_info;
            symbol_tables[i].size = symbol.st_size;
        }
        symbol_tables_size = num_symbols;
    }

    // 关闭文件并释放内存
    fclose(fp);
    free(string_table);
}

/**
 * 根据地址返回对应函数在symbols中的下标
 * 如果是ret函数，地址为[addr,addr + size]即可
*/
int symbol_index(paddr_t addr, bool is_call) {
    int i;
    for (i = 0; i < symbol_tables_size; i++) {
        if (ELF64_ST_TYPE(symbol_tables[i].info) == STT_FUNC) {
            if (is_call) {
                if (symbol_tables[i].addr == addr) 
                    break;
            }
            else {
                if (symbol_tables[i].addr <= addr && addr < symbol_tables[i].addr + symbol_tables[i].size)
                    break;
            }
        }
    }
    return i == symbol_tables_size ? -1 : i;
}

/**
 * 记录call指令
*/
void call_trace(paddr_t pc, paddr_t npc) {
    if (symbol_tables == NULL)
        return;
    int i = symbol_index(npc, true);
    Log(FMT_PADDR":call [%s@"FMT_PADDR"]\n", pc, symbol_tables[i].name, npc);
}

/**
 * 记录ret指令
*/
void ret_trace(paddr_t pc) {
    if (symbol_tables == NULL)
        return;
    int i = symbol_index(pc, false);
    Log(FMT_PADDR":ret [%s]", pc, symbol_tables[i].name);
}