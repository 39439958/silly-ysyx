#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
# define ebreak(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

#define DEVICE_BASE 0xa0000000
#define SERIAL_PORT (DEVICE_BASE + 0x00003f8)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
  pmem_write(SERIAL_PORT, ch, 0);
}

void halt(int code) {
  ebreak(code);
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
