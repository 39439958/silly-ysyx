#include <am.h>

bool ioe_init() {
  return true;
}

void ioe_read (int reg, void *buf) {
  int am_ioe_fd = open("/dev/am_ioe", 0, 0);
  lseek(am_ioe_fd, reg, SEEK_SET);
  read(am_ioe_fd, buf, 0);
  close(am_ioe_fd);
}
void ioe_write(int reg, void *buf) {
  int am_ioe_fd = open("/dev/am_ioe", 0, 0);
  lseek(am_ioe_fd, reg, SEEK_SET);
  write(am_ioe_fd, buf, 0);
  close(am_ioe_fd);
}
