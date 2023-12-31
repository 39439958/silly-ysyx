#include "fixedptc.h"
#include <stdio.h>

int main() {
  fixedpt a = fixedpt_rconst(1.2);
  fixedpt b = fixedpt_rconst(-1.2);
  int c = 3;
  printf("%d\n",fixedpt_floor(a) >> 8);
  printf("%d\n",fixedpt_ceil(a) >> 8);
  printf("%d\n",fixedpt_floor(b) >> 8);
  printf("%d\n",fixedpt_ceil(b) >> 8);
  printf("%d %d\n", b, fixedpt_abs(b));
  printf("%d %d\n", fixedpt_muli(a, c), fixedpt_divi(a, c));
  printf("%d %d\n", fixedpt_muli(b, c), fixedpt_divi(b, c));
  printf("%d %d\n", fixedpt_mul(a, b), fixedpt_div(a, b));
  printf("%d\n", 0xfffffe00);
}