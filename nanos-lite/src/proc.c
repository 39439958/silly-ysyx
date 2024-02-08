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
  // uintptr_t entry = naive_uload(p, filename);

  // // int argc = 0, envc = 0;
  // // while (argv[argc] != NULL) argc++;
  // // while (envp[envc] != NULL) envc++;

  // // uintptr_t* us = (uintptr_t*)heap.end;

  // // // clone argv
  // // for (int i = 0; i < argc; i++) {
  // //   size_t len = strlen(argv[i]) + 1; // include null character
  // //   us -= len;
  // //   strncpy((char *)us, argv[i], len);
  // // }
  // // us = (uintptr_t*)((uintptr_t)us & ~(sizeof(uintptr_t) - 1)); // floor

  // // // clone envp
  // // for (int i = 0; i < envc; i++) {
  // //   size_t len = strlen(envp[i]) + 1; // include null character
  // //   us -= len;
  // //   strncpy((char*)us, envp[i], len);
  // // }
  // // us = (uintptr_t*)((uintptr_t)us & ~(sizeof(uintptr_t) - 1)); // floor

  // // us -= (argc + envc + 3);

  // // us[0] = argc;

  // // uintptr_t* us_tmp = (uintptr_t*)heap.end;
  // // for (int i = 0; i < argc; i++) {
  // //   size_t len = strlen(argv[i]) + 1;
  // //   us_tmp -= len;
  // //   us[i + 1] = (uintptr_t)us_tmp;
  // // }
  // // us_tmp = (uintptr_t*)((uintptr_t)us_tmp & ~(sizeof(uintptr_t) - 1)); // floor

  // // us[argc + 1] = 0;

  // // for (int i = 0; i < envc; i++) {
  // //   size_t len = strlen(envp[i]) + 1; // include null character
  // //   us_tmp -= len;
  // //   us[argc + 2 + i] = (uintptr_t)us_tmp;
  // // }

  // // us[argc + envc + 2] = 0;

  // p->cp = ucontext(&p->as, (Area) { p->stack, p + 1 }, (void *)entry);
  // p->cp->GPRx = (uintptr_t)us;

  // 定义用户栈的区域
    Area stack;
    stack.start = pcb->stack;
    stack.end = pcb->stack + STACK_SIZE;
 
    // 调用 loader 函数加载用户程序，获取入口地址
    uintptr_t entry = naive_uload(pcb, filename);
 
    // 计算 argc、envc 的值
    int argc = 0;
    while (argv[argc] != NULL) argc++;
    int envc = 0;
    while (envp[envc] != NULL) envc++;
 
    // 分配用户栈空间，用于存储 argv 和 envp 指针
    uintptr_t* user_stack = (uintptr_t*)heap.end;
 
    // 将 argv 字符串逆序拷贝到用户栈
    for (int i = argc - 1; i >= 0; i--) {
        size_t len = strlen(argv[i]) + 1;  // 包括 null 终止符
        user_stack -= len;
        strncpy((char*)user_stack, argv[i], len);
    }
 
    // 对齐到 uintptr_t 边界
    user_stack = (uintptr_t*)((uintptr_t)user_stack & ~(sizeof(uintptr_t) - 1));
 
    // 将 envp 字符串逆序拷贝到用户栈
    for (int i = envc - 1; i >= 0; i--) {
        size_t len = strlen(envp[i]) + 1;  // 包括 null 终止符
        user_stack -= len;
        strncpy((char*)user_stack, envp[i], len);
    }
 
    // 对齐到 uintptr_t 边界
    user_stack = (uintptr_t*)((uintptr_t)user_stack & ~(sizeof(uintptr_t) - 1));
 
    // 将 argv 和 envp 指针拷贝到用户栈
    user_stack -= (argc + envc + 4);  // +4 为 NULL 结尾和 argc/envc 的值
 
    // 设置 argc 的值
    user_stack[0] = argc;
 
    // 设置 argv 指针
    for (int i = 0; i < argc; i++) {
        user_stack[i + 1] = (uintptr_t)heap.end - (argc - i - 1) * sizeof(uintptr_t);
    }
 
    // 设置 argv 的 NULL 终止符
    user_stack[argc + 1] = 0;
 
    // 设置 envc 的值
    user_stack[argc + 2] = envc;
 
    // 设置 envp 指针
    for (int i = 0; i < envc; i++) {
        user_stack[argc + 3 + i] = (uintptr_t)heap.end - (argc + 3 + envc - i - 1) * sizeof(uintptr_t);
    }
 
    // 设置 envp 的 NULL 终止符
    user_stack[argc + 3 + envc] = 0;
 
    // 调用 ucontext 函数创建用户上下文，传入入口地址和用户栈
    pcb->cp = ucontext(&p->as, stack, (void*)entry);
 
    // 将用户栈的顶部地址赋给 GPRx 寄存器
    pcb->cp->GPRx = (uintptr_t)user_stack;
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
