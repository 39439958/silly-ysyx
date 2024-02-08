#include <common.h>

void do_syscall(Context *c);
Context* schedule(Context *prev);

static Context* do_event(Event e, Context* c) {
  switch (e.event) {
    case EVENT_YIELD : c = schedule(c); c->mepc += 4; break;
    case EVENT_SYSCALL : do_syscall(c); c->mepc += 4; break;
    default: panic("irq:Unhandled event ID = %d", e.event);
  }

  return c;
}

void init_irq(void) {
  Log("Initializing interrupt/exception handler...");
  cte_init(do_event);
}
