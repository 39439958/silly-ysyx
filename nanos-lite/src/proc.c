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

void context_uload(PCB *p, const char *filename, char *const argv[], char *const envp[]) {
  uintptr_t entry = naive_uload(p, filename);

  int argc = 0, envc = 0;
  while (argv[argc] != NULL) argc++;
  while (envp[envc] != NULL) envc++;

  uintptr_t* us = (uintptr_t*)heap.end;

  printf("heap.end:%d\n", *us);

  // // clone argv
  // for (int i = 0; i < argc; i++) {
  //   size_t len = strlen(argv[i]) + 1; // include null character
  //   us -= len;
  //   strncpy((char *)us, argv[i], len);
  // }
  // us = (uintptr_t*)((uintptr_t)us & ~(sizeof(uintptr_t) - 1)); // floor

  // // clone envp
  // for (int i = 0; i < envc; i++) {
  //   size_t len = strlen(envp[i]) + 1; // include null character
  //   us -= len;
  //   strncpy((char*)us, envp[i], len);
  // }
  // us = (uintptr_t*)((uintptr_t)us & ~(sizeof(uintptr_t) - 1)); // floor

  // us -= (argc + envc + 3);

  // us[0] = argc;

  // uintptr_t* us_tmp = (uintptr_t*)heap.end;
  // for (int i = 0; i < argc; i++) {
  //   size_t len = strlen(argv[i]) + 1;
  //   us_tmp -= len;
  //   us[i + 1] = *us_tmp;
  // }
  // us_tmp = (uintptr_t*)((uintptr_t)us_tmp & ~(sizeof(uintptr_t) - 1)); // floor

  // us[argc + 1] = 0;

  // for (int i = 0; i < envc; i++) {
  //   size_t len = strlen(envp[i]) + 1; // include null character
  //   us_tmp -= len;
  //   us[argc + 2 + i] = *us_tmp;
  // }

  // us[argc + envc + 2] = 0;

  p->cp = ucontext(&p->as, (Area) { p->stack, p + 1 }, (void *)entry);
  p->cp->GPRx = (uintptr_t)us;
}

void init_proc() {
  context_kload(&pcb[0], hello_fun, (void *)2L);
  context_uload(&pcb[1], "/bin/pal", NULL, NULL);
  switch_boot_pcb();

  Log("Initializing processes...");

  // load program here
  // naive_uload(NULL, "/bin/nterm");
}

Context* schedule(Context *prev) {
  current->cp = prev;
  current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
  return current->cp;
}
