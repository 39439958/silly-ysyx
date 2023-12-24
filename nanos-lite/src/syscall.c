#include <common.h>
#include "syscall.h"

#define strace(); Log("strace : %s , a0 : %d, a1 : %d, a2 : %d, ret : %d\n", a[0], a0, a[2], a[3], c->GPRx);

void yield();
void halt(int code);
void putch(char ch);

int sys_yield() {
  yield();
  return 0;
}

void sys_exit(int code) {
  halt(code);
}

int sys_write(int fd, char *buf, size_t len) {
  if (fd == 1 || fd == 2) {
    for (int i = 0; i < len; i++) {
      putch(buf[i]);
    }
  }
  return len;
}


void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  uintptr_t a0 = a[1];

  switch (a[0]) {
    case SYS_exit : 
      strace(); 
      sys_exit(a[0]); 
      break;
    case SYS_yield : 
      c->GPRx = sys_yield(); 
      strace(); 
      break;
    case SYS_write : 
      c->GPRx = sys_write(a[1], (char *)a[2], a[3]);
      strace(); 
      break;
    case SYS_brk :
      c->GPRx = 0;
      strace();
      break;
    default : panic("syscall:Unhandled syscall ID = %d", a[0]);
  }
}
