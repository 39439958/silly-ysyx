#include <common.h>

typedef struct iringbuf
{
  vaddr_t pcs[20];
  uint32_t insts[20];
  uint32_t iring_rf;
  uint32_t iring_wf;
}iringbuf;

iringbuf irb;

void iringbuf_write_inst(vaddr_t pc, uint32_t inst) {
  irb.pcs[irb.iring_wf] = pc;
  irb.insts[irb.iring_wf] = inst;
  irb.iring_wf = (irb.iring_wf + 1) % 20;
  if (irb.iring_wf == irb.iring_rf)
    irb.iring_rf = (irb.iring_rf + 1) % 20;
}

void iringbuf_display() {
  
  
}

