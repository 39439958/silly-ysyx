#include <am.h>
#include <riscv/riscv.h>
#include <arch/riscv.h>
#include <klib.h>
#include <nemu.h>

#define IRQ_TIMER 0x80000007  // for riscv32

static Context* (*user_handler)(Event, Context*) = NULL;

void __am_get_cur_as(Context *c);
void __am_switch(Context *c);

Context* __am_irq_handle(Context *c) {
  __am_get_cur_as(c);
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 0: case 1: case 2: case 3: case 4: case 7: case 8: case 9: case 13: case 19: ev.event = EVENT_SYSCALL; break;
      case IRQ_TIMER: ev.event = EVENT_IRQ_TIMER; break;
      case -1: ev.event = EVENT_YIELD; break;
      default: ev.event = EVENT_ERROR; break;
    }
    c = user_handler(ev, c);
    assert(c != NULL);
  }
  __am_switch(c);
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  // printf("pmem_start:%p, pmem_end:%p\n", &_pmem_start, PMEM_END);
  // printf("head_start:%p\n", _heap_start);

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  // printf("kstack.start:%p, kstack.end:%p\n", kstack.start, kstack.end);
  Context *cp = (Context *)(kstack.end - sizeof(Context));
  cp->mepc = (uintptr_t)entry - 4;
  cp->gpr[10] = (uintptr_t)(arg);
  cp->pdir = NULL;
  cp->mstatus = 0x1800 | 0x00000080;
  return cp;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
