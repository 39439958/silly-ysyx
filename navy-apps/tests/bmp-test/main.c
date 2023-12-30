#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <NDL.h>
#include <BMP.h>

int main() {
  NDL_Init(0);
  int w, h;
  uint32_t *bmp = BMP_Load("/share/pictures/projectn.bmp", &w, &h);
  assert(bmp);
  for (int i = 0; i < h; i ++) {
    for (int j = 0; j < w; j ++) {
      printf("%d\n", bmp[i * w + j]);
    }
  }
  NDL_OpenCanvas(&w, &h);
  NDL_DrawRect(bmp, 0, 0, w, h);
  free(bmp);
  NDL_Quit();
  printf("Test ends! Spinning...\n");
  while (1);
  return 0;
}
