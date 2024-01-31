#include <proc.h>
#include <am.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static PCB pcb_boot = {};
PCB *current = NULL;

uintptr_t naive_uload(PCB *pcb, const char *filename);

void switch_boot_pcb() {
  current = &pcb_boot;
}

void hello_fun(void *arg) {
  int j = 1;
  while (1) {
    Log("Hello World from Nanos-lite with arg '%p' for the %dth time!", (uintptr_t)arg, j);
    j ++;
    yield();
  }
}

void context_kload(PCB *p, void (*entry)(void *), void *arg) {
  p->cp = kcontext((Area) { p->stack, p + 1 }, hello_fun, arg);
}

void context_uload(PCB *p, const char *filename) {
  uintptr_t entry = naive_uload(p, filename);
  p->cp = ucontext(&p->as, (Area) { p->stack, p + 1 }, (void *)entry);
  p->cp->GPRx = (uintptr_t)heap.end;
}

void init_proc() {
  context_kload(&pcb[0], hello_fun, (void *)2L);
  context_uload(&pcb[1], "/bin/pal");
  switch_boot_pcb();

  Log("Initializing processes...");

  // load program here
  //naive_uload(NULL, "/bin/nterm");
}

Context* schedule(Context *prev) {
  current->cp = prev;
  current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
  return current->cp;
}
