#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;
static int canvas_w = 0, canvas_h = 0;

static uint32_t init_time = 0;
static int event_fd = 0;
static int vga_fd = 0;
static int fb_fd = 0;


uint32_t NDL_GetTicks() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  // 返回毫秒数
  uint32_t now_time = (uint32_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000) - init_time;
  return now_time;
}

int NDL_PollEvent(char *buf, int len) {
  return read(event_fd, buf, len);
}

void NDL_OpenCanvas(int *w, int *h) {
  if (getenv("NWM_APP")) {
    int fbctl = 4;
    fbdev = 5;
    screen_w = *w; screen_h = *h;
    char buf[64];
    int len = sprintf(buf, "%d %d", screen_w, screen_h);
    // let NWM resize the window and create the frame buffer
    write(fbctl, buf, len);
    while (1) {
      // 3 = evtdev
      int nread = read(3, buf, sizeof(buf) - 1);
      if (nread <= 0) continue;
      buf[nread] = '\0';
      if (strcmp(buf, "mmap ok") == 0) break;
    }
    close(fbctl);
  }
  assert(screen_h >= *h && screen_w >= *w);
  // 设置canvas大小
  if (*w == 0 && *h == 0) {
    canvas_h = screen_h;
    canvas_w = screen_w;
    *w = screen_w;
    *h = screen_h;
  } else {
    canvas_h = *h;
    canvas_w = *w;
  }
  
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
  x += (screen_w - canvas_w) / 2;
  y += (screen_h - canvas_h) / 2;
  for (int i = 0; i < h; i++) {
    int offset = (y + i)* screen_w + x;
    lseek(fb_fd, offset, SEEK_SET);
    write(fb_fd, pixels + (i * w), w);
  }
}

void NDL_OpenAudio(int freq, int channels, int samples) {
}

void NDL_CloseAudio() {
}

int NDL_PlayAudio(void *buf, int len) {
  return 0;
}

int NDL_QueryAudio() {
  return 0;
}

int NDL_Init(uint32_t flags) {
  if (getenv("NWM_APP")) {
    evtdev = 3;
  }

  // 初始化时间
  struct timeval tv;
  gettimeofday(&tv, NULL);
  init_time = (uint32_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000);

  // 打开键盘事件
  event_fd = open("/dev/event", "r");
  
  // 打开vga的dispinfo文件并解析出屏幕大小
  vga_fd = open("proc/dispinfo", "r");
  char buf[64];
  read(vga_fd, buf, sizeof(buf));
  sscanf(buf, "WIDTH:%d\nHEIGHT:%d\n", &screen_w, &screen_h);

  // 打开vga的fb
  fb_fd = open("/dev/fb", "w");

  return 0;
}

void NDL_Quit() {
  // 关闭键盘事件
  close(event_fd);

  // 关闭dispinfo文件
  close(vga_fd);

  // 关闭fb
  close(fb_fd);
}
