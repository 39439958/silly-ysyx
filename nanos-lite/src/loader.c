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

size_t ramdisk_read(void *buf, size_t offset, size_t len);

int fs_open(const char *pathname, int flags, int mode);
size_t fs_read(int fd, void *buf, size_t len);
size_t fs_lseek(int fd, size_t offset, int whence);
int fs_close(int fd);

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

  for (int i = 0; i < ehdr.e_phnum; i++) {
    if (ph[i].p_type == PT_LOAD) {
      fs_lseek(fd, ph[i].p_offset, SEEK_SET);
      fs_read(fd, (void *)ph[i].p_vaddr, ph[i].p_memsz);
      memset((void *)(ph[i].p_vaddr + ph[i].p_filesz), 0, ph[i].p_memsz - ph[i].p_filesz);
    }
  }
printf("666\n");
  fs_close(fd);
  return ehdr.e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

