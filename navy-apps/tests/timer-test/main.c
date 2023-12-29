#include <stdio.h>
#include <stdint.h>
#include <NDL.h>

// int NDL_Init(uint32_t flags);
// void NDL_Quit();
// uint32_t NDL_GetTicks();

int main() {
  NDL_Init(0);

  uint32_t now_time = NDL_GetTicks();
  uint32_t ms = 500;
  while (ms <= 10000) {
    while ((now_time / 1000) < ms) {
      now_time = NDL_GetTicks();
    }
    printf("ms = %d\n", ms);
    ms += 500;
  }
  NDL_Quit();
}
