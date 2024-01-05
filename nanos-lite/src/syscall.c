#include <common.h>
#include <proc.h>
#include "syscall.h"

#define strace(); Log("[strace] : %s , a0 : %d, a1 : %d, a2 : %d, ret : %d\n", syscall_name[a[0]], a0, a[2], a[3], c->GPRx);

struct timeval {
	long	tv_sec;		/* seconds */
	long	tv_usec;	/* and microseconds */
};

struct timezone {
	int	tz_minuteswest;	/* minutes west of Greenwich */
	int	tz_dsttime;	/* type of dst correction */
};

static char* syscall_name[] = {"exit", "yield", "open", "read",
                               "write", "kill", "getpid", "close",
                               "lseek", "brk", "fstat", "time",
                               "signal", "execve", "fork", "link",
                               "unlink", "wait", "times", "gettimeofday"};
// am
void yield();
void halt(int code);
void putch(char ch);

// os
void naive_uload(PCB *pcb, const char *filename);

// file system call
int fs_open(const char *pathname, int flags, int mode);
size_t fs_read(int fd, void *buf, size_t len);
size_t fs_write(int fd, const void *buf, size_t len);
size_t fs_lseek(int fd, size_t offset, int whence);
int fs_close(int fd);

int sys_execve(const char *pathname, char *const argv[], char *const envp[]);

int sys_yield() {
  yield();
  return 0;
}

void sys_exit(int code) {
  sys_execve("/bin/nterm", NULL, NULL);
  //halt(code);
}

int sys_gettimeofday(struct timeval *tv, struct timezone* tz) {
  assert(tv != NULL);
  int us = 0;
  ioe_read(AM_TIMER_UPTIME, &us);
  tv->tv_sec = us / (1000*1000);
  tv->tv_usec = us % (1000*1000);
  return 0;
}

int sys_execve(const char *pathname, char *const argv[], char *const envp[]) {
  if (pathname == NULL)
    return -1;
  naive_uload(NULL, pathname);
  return 0;
}

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1; // a7
  a[1] = c->GPR2; // a0
  a[2] = c->GPR3; // a1
  a[3] = c->GPR4; // a2

  uintptr_t a0 = a[1];

  switch (a[0]) {
    case SYS_exit : 
      strace(); 
      sys_exit(a[0]); 
      break;
    case SYS_yield : 
      c->GPRx = sys_yield(); 
      break;
    case SYS_brk :
      c->GPRx = 0;
      break;
    case SYS_write : 
      c->GPRx = fs_write(a[1], (char *)a[2], a[3]);
      break;
    case SYS_open :
      c->GPRx = fs_open((char *)a[1], a[2], a[3]);
      Log("open file : %s, fd :%d\n", (char *)a[1], c->GPRx);
      break;
    case SYS_read :
      c->GPRx = fs_read(a[1], (char *)a[2], a[3]);
      break;
    case SYS_lseek :
      c->GPRx = fs_lseek(a[1], a[2], a[3]);
      break;
    case SYS_close :
      c->GPRx = fs_close(a[1]);
      break;
    case SYS_gettimeofday :
      c->GPRx = sys_gettimeofday((struct timeval *)a[1], (struct timezone *)a[2]);
      break;
    case SYS_execve :
      c->GPRx = sys_execve((char *)a[1], (char * const *)a[2], (char * const *)a[3]);
      break;
    default : panic("syscall:Unhandled syscall ID = %d", a[0]);
  }
  //strace();
}
