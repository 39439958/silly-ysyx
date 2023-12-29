#include <stdio.h>

int main() {
  struct timeval tv;
  gettimeofday(&tv, NULL);

  int ms = 500;
  while (1) {
    while ((tv.tv_sec * 1000 + tv.tv_usec / 1000) < ms) {
      gettimeofday(&tv, NULL);
    }
    printf("time %d ", tv.tv_sec);
    printf("ms = %d\n", ms);
    ms += 500;
  }
}
