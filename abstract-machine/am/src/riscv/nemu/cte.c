#include <am.h>
#include <riscv/riscv.h>
#include <arch/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 0: ev.event = EVENT_SYSCALL; break;
      case 11: ev.event = EVENT_YIELD; break;
      case 1: ev.event = EVENT_SYSCALL; break;
      case 4: ev.event = EVENT_SYSCALL; break;
      case 9: ev.event = EVENT_SYSCALL; break;
      default: ev.event = EVENT_ERROR; break;
    }
    // print reg and csr
    printf("[REG]:\n");
    for (int i = 0; i < 32; i++) {
      printf("gpr[%d] : %d ", i, c->gpr[i]);
      if (i % 4 == 3) printf("\n");
    }
    printf("[CSR]:\n");
    printf("mcause : %d, mstatus : %d, mepc : %d\n", c->mcause, c->mstatus, c->mepc);
    
    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, 0xb; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
