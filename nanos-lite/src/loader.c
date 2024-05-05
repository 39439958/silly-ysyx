#include <math.h>
#include <proc.h>
#include <elf.h>
#include <fs.h>

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

#if defined(__ISA_AM_NATIVE__)
# define EXPECT_TYPE EM_X86_64
#elif defined(__riscv)
# define EXPECT_TYPE EM_RISCV  // see /usr/include/elf.h to get the right type
#else 
# error Unsupported ISA
#endif

#define min(x, y) ((x < y) ? x : y)

// some bit operator for page  
#define PG_MASK (~0xfff)
#define ISALIGN(vaddr) ((vaddr) == ((vaddr)&PG_MASK))
#define OFFSET(vaddr) ((vaddr) & (~PG_MASK))
#define NEXT_PAGE(vaddr) ((ISALIGN(vaddr)) ? (vaddr) : ((vaddr)&PG_MASK) + PGSIZE)

// ramdisk function
// size_t ramdisk_read(void *buf, size_t offset, size_t len);

// filesystem function
int fs_open(const char *pathname, int flags, int mode);
size_t fs_read(int fd, void *buf, size_t len);
size_t fs_lseek(int fd, size_t offset, int whence);
int fs_close(int fd);

// memory function
void* new_page(size_t nr_page);


/*
 *  load program in memory
 *  pcb: 
 */
static uintptr_t loader(PCB *pcb, const char *filename) {
  int fd = fs_open(filename, 0, 0);

  // open elf
  Elf_Ehdr ehdr;
  fs_read(fd, &ehdr, sizeof(Elf_Ehdr));
  assert(*(uint32_t *)ehdr.e_ident == 0x464c457f);

  // check elf type
  assert(ehdr.e_machine == EXPECT_TYPE);

  // read phdr
  Elf_Phdr ph[ehdr.e_phnum];
  fs_lseek(fd, ehdr.e_phoff, SEEK_SET);
  fs_read(fd, ph, sizeof(Elf_Phdr)*ehdr.e_phnum);

  // load program
  for (int i = 0; i < ehdr.e_phnum; i++) {
    if (ph[i].p_type == PT_LOAD) {
      uint32_t offset = ph[i].p_offset;
      uint32_t p_vaddr = ph[i].p_vaddr;
      uint32_t file_size = ph[i].p_filesz;
      uint32_t mem_size = ph[i].p_memsz;
      
      printf("load program from [%p, %p] to [%p, %p]\n", offset, file_size, p_vaddr, mem_size);

      int left_size = file_size;
      fs_lseek(fd, offset, SEEK_SET);
      if (!ISALIGN(p_vaddr))
      {
        void *pg_p = new_page(1);
        int read_len = min(PGSIZE - OFFSET(p_vaddr), left_size);
        left_size -= read_len;
        assert(fs_read(fd, pg_p + OFFSET(p_vaddr), read_len) >= 0);
        map(&pcb->as, (void *)p_vaddr, pg_p, PTE_R | PTE_W | PTE_X);
        p_vaddr += read_len;
      }

      for (; p_vaddr < ph[i].p_vaddr + file_size; p_vaddr += PGSIZE)
      {
        assert(ISALIGN(p_vaddr));
        void *pg_p = new_page(1);
        memset(pg_p, 0, PGSIZE);
        int read_len = min(PGSIZE, left_size);
        left_size -= read_len;
        assert(fs_read(fd, pg_p, read_len) >= 0);
        map(&pcb->as, (void *)p_vaddr, pg_p, PTE_R | PTE_W | PTE_X);
      }
      p_vaddr = NEXT_PAGE(p_vaddr);
      for (; p_vaddr < ph[i].p_vaddr + mem_size; p_vaddr += PGSIZE)
      {
        assert(ISALIGN(p_vaddr));
        void *pg_p = new_page(1);
        memset(pg_p, 0, PGSIZE);
        map(&pcb->as, (void *)p_vaddr, pg_p, PTE_R | PTE_W | PTE_X);
      }
      assert(mem_size >= file_size);
    }
  }
  fs_close(fd);
  return ehdr.e_entry;
}

/* 
 * load program and return program entry 
 */
uintptr_t naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  return entry;
  // Log("Jump to entry = %p", entry);
  // ((void(*)())entry) ();
}

