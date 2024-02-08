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

  char* us1 = (char*)new_page(8);
  // clone argv
  for (int i = 0; i < argc; i++) {
    size_t len = strlen(argv[i]) + 1; // include null character
    us1 -= len;
    strncpy(us1, argv[i], len);
  }
  // clone envp
  for (int i = 0; i < envc; i++) {
    size_t len = strlen(envp[i]) + 1; // include null character
    us1 -= len;
    strncpy(us1, envp[i], len);
  }

  uintptr_t* us2 = (uintptr_t *)us1;
  us2 -= (argc + envc + 3);

  us2[0] = argc;

  char* us_tmp = (char*)heap.end;
  for (int i = 0; i < argc; i++) {
    size_t len = strlen(argv[i]) + 1; 
    us_tmp -= len;
    us2[i + 1] = (uintptr_t)us_tmp;
  }
  us2[argc + 1] = 0;
  for (int i = 0; i < envc; i++) {
    size_t len = strlen(envp[i]) + 1; // include null character
    us_tmp -= len;
    us2[argc + i + 2] = (uintptr_t)us_tmp;
  }
  us2[argc + 2 + envc] = 0;

  p->cp = ucontext(&p->as, (Area) { p->stack, p + 1 }, (void *)entry);
  p->cp->GPRx = (uintptr_t)us2;
}

void init_proc() {
  // context_kload(&pcb[0], hello_fun, (void *)1L);
  // context_kload(&pcb[1], hello_fun, (void *)2L);

  char *argv[] = {NULL}; 
  char *envp[] = {NULL}; 
  context_uload(&pcb[0], "/bin/exec-test", argv, envp);
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
