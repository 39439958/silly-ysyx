#include <proc.h>
#include <elf.h>

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

static uintptr_t loader(PCB *pcb, const char *filename) {
  // open elf
  Elf_Ehdr ehdr;
  ramdisk_read(&ehdr, 0, sizeof(Elf_Ehdr));
  assert(*(uint32_t *)ehdr.e_ident == 0x464c457f);

  // check elf type
  assert(ehdr.e_machine == EXPECT_TYPE);

  // read phdr
  Elf_Phdr ph[ehdr.e_phnum];
  ramdisk_read(ph, ehdr.e_phoff, sizeof(Elf_Phdr)*ehdr.e_phnum);
  for (int i = 0; i < ehdr.e_phnum; i++) {
    if (ph[i].p_type == PT_LOAD) {
      ramdisk_read((void *)ph[i].p_vaddr, ph[i].p_offset, ph[i].p_memsz);
      memset((void *)(ph[i].p_vaddr + ph[i].p_filesz), 0, ph[i].p_memsz - ph[i].p_filesz);
    }
  }
  Log("vaddr: %p\n",(void *)ph[2].p_vaddr);
  return ehdr.e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

