#include <proc.h>
#include <am.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
//static PCB pcb_boot = {};
PCB *current = NULL;

void naive_uload(PCB *pcb, const char *filename);

void switch_boot_pcb() {
  current = &pcb[0];
}

void hello_fun(void *arg) {
  int j = 1;
  while (1) {
    Log("Hello World from Nanos-lite with arg '%p' for the %dth time!", (uintptr_t)arg, j);
    j ++;
    yield();
  }
}

void context_kload(PCB *pcb, void (*entry)(void *), void *arg) {
  pcb->cp = kcontext((Area) { pcb[0].stack, &pcb[0] + 1 }, hello_fun, arg);
}

void init_proc() {
  context_kload(&pcb[0], hello_fun, (void *)1L);
  context_kload(&pcb[1], hello_fun, (void *)2L);
  switch_boot_pcb();
  printf("666\n");
  yield();

  Log("Initializing processes...");

  // load program here
  //naive_uload(NULL, "/bin/nterm");
}

Context* schedule(Context *prev) {
  current->cp = prev;
  current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
  current->cp->mepc += 4;
  return current->cp;
}
