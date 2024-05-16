#include <am.h>
#include <nemu.h>
#include <klib.h>

static AddrSpace kas = {};
static void* (*pgalloc_usr)(int) = NULL;
static void (*pgfree_usr)(void*) = NULL;
static int vme_enable = 0;

static Area segments[] = {      // Kernel memory mappings
  NEMU_PADDR_SPACE
};

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static inline void set_satp(void *pdir) {
  uintptr_t mode = 1ul << (__riscv_xlen - 1);
  asm volatile("csrw satp, %0" : : "r"(mode | ((uintptr_t)pdir >> 12)));
}

static inline uintptr_t get_satp() {
  uintptr_t satp;
  asm volatile("csrr %0, satp" : "=r"(satp));
  return satp << 12;
}

bool vme_init(void* (*pgalloc_f)(int), void (*pgfree_f)(void*)) {
  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;

  kas.ptr = pgalloc_f(PGSIZE);

  int i;
  for (i = 0; i < LENGTH(segments); i ++) {
    void *va = segments[i].start;
    for (; va < segments[i].end; va += PGSIZE) {
      map(&kas, va, va, PTE_R | PTE_W | PTE_X);
    }
  }

  set_satp(kas.ptr);
  vme_enable = 1;

  return true;
}

void protect(AddrSpace *as) {
  PTE *updir = (PTE*)(pgalloc_usr(PGSIZE));
  as->ptr = updir;
  as->area = USER_SPACE;
  as->pgsize = PGSIZE;
  // map kernel space
  memcpy(updir, kas.ptr, PGSIZE);
}

void unprotect(AddrSpace *as) {
}

void __am_get_cur_as(Context *c) {
  if (c->pdir != NULL) {
    c->pdir = (vme_enable ? (void *)get_satp() : NULL);
  }
}

void __am_switch(Context *c) {
  if (vme_enable && c->pdir != NULL) {
    set_satp(c->pdir);
  }
}

#define PGT1_INDEX(i) (i >> 22)
#define PGT2_INDEX(i) ((i & 0x3fffff) >> 12)
void map(AddrSpace *as, void *va, void *pa, int prot) {
  uint32_t pa_raw = (uint32_t)pa;
  uint32_t va_raw = (uint32_t)va;
  uint32_t **pt1 = (uint32_t **)as->ptr;
  if (pt1[PGT1_INDEX(va_raw)] == NULL) {
    pt1[PGT1_INDEX(va_raw)] = (uint32_t *)pgalloc_usr(PGSIZE);
  }
  uint32_t *pt2 = pt1[PGT1_INDEX(va_raw)];
  if (pt2[PGT2_INDEX(va_raw)] == 0) {
    pt2[PGT2_INDEX(va_raw)] = (pa_raw & (~0xfff)) | prot;
  } else {
    assert(0);
  }
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry) {
  Context *cp = (Context *)(kstack.end - sizeof(Context));
  memset(cp, 0, sizeof(cp));
  cp->mepc = (uintptr_t)entry - 4;
  cp->gpr[0] = 0;
  cp->pdir = as->ptr;
  cp->mstatus = 0x1800 | 0x00000080;
  return cp;
}
