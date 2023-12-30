#include <common.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
# define MULTIPROGRAM_YIELD() yield()
#else
# define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
  [AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
  [AM_KEY_NONE] = "NONE",
  AM_KEYS(NAME)
};

static int screen_w = 0, screen_h = 0;
AM_GPU_FBDRAW_T fb_ctl;

size_t serial_write(const void *buf, size_t offset, size_t len) {
  char *cbuf = (char *)buf;
  for (int i = 0; i < len; i++) {
    putch(cbuf[i]);
  } 
  return len;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  AM_INPUT_KEYBRD_T kbd;
  ioe_read(AM_INPUT_KEYBRD, &kbd);
  int ret = 0;
  if (kbd.keycode == AM_KEY_NONE) {
    *(char *)buf = '\0';
  } else {
    ret = sprintf((char *)buf, "%s %s\n", kbd.keydown ? "kd" : "ku", keyname[kbd.keycode]);
  }
  return ret;
}

size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  AM_GPU_CONFIG_T cfg;
  ioe_read(AM_GPU_CONFIG, &cfg);
  sprintf((char *)buf, "WIDTH:%d\nHEIGHT:%d\n", cfg.width, cfg.height);
  screen_h = cfg.height;
  screen_w = cfg.width;
  return 0;
}

size_t fb_write(const void *buf, size_t offset, size_t len) {
  // strncpy(fb_ctl.pixels, buf, 1);
  fb_ctl.x = offset / screen_w;
  fb_ctl.y = offset % screen_w;
  fb_ctl.w = len, fb_ctl.h = 1;
  fb_ctl.sync = true;

  ioe_read(AM_GPU_FBDRAW, &fb_ctl);

  return 0;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
