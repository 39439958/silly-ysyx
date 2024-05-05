#include <memory.h>
#include <proc.h>

#define PG_MASK ~0xfff

static void *pf = NULL;
extern PCB *current;

void* new_page(size_t nr_page) {
  void *old_pf = pf;
  pf += nr_page * PGSIZE;
  return old_pf;
}

#ifdef HAS_VME
static void* pg_alloc(int n) {
  assert(n >= PGSIZE);
  void *ret = new_page(n / PGSIZE);
  return memset(ret, 0, n);
}
#endif

void free_page(void *p) {
  panic("not implement yet");
}

/* The brk() system call handler. */
int mm_brk(uintptr_t brk) {
  if (current->max_brk == 0)
  {
    current->max_brk = (brk & ~PG_MASK) ? ((brk & PG_MASK) + PGSIZE) : brk;
    return 0;
  }

  for (; current->max_brk < brk; current->max_brk += PGSIZE) {
    map(&current->as, (void *)current->max_brk, pg_alloc(PGSIZE), PTE_R | PTE_W | PTE_X);
  }
  return 0;
}

void init_mm() {
  pf = (void *)ROUNDUP(heap.start, PGSIZE);
  Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
  vme_init(pg_alloc, free_page);
#endif
}
