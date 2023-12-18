#include <common.h>
#include "syscall.h"

void yield();
void halt (int code);

int sys_yield() {
  yield();
  return 0;
}

void sys_exit(int code) {
  halt(code);
}

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;

  switch (a[0]) {
    case SYS_exit: sys_exit(a[0]); break;
    case SYS_yield: a[0] = sys_yield(); break;
    default: panic("syscall:Unhandled syscall ID = %d", a[0]);
  }
}
