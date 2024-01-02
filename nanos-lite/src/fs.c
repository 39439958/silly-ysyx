#include <fs.h>

typedef size_t (*ReadFn) (void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn) (const void *buf, size_t offset, size_t len);

size_t ramdisk_read(void *buf, size_t offset, size_t len);
size_t ramdisk_write(const void *buf, size_t offset, size_t len);

size_t serial_write(const void *buf, size_t offset, size_t len);
size_t events_read(void *buf, size_t offset, size_t len);
size_t dispinfo_read(void *buf, size_t offset, size_t len);
size_t fb_write(const void *buf, size_t offset, size_t len);

typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
  size_t open_offset;
} Finfo;

enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_EVENT, FD_FB, FB_DP};


size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("Should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("Should not reach here");
  return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN]  = {"stdin", 0, 0, invalid_read, serial_write},
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, serial_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, invalid_write},
  [FD_EVENT] = {"/dev/event", 0 ,0, events_read, invalid_write},
  [FD_FB] = {"/dev/fb", 0, 0, invalid_read, fb_write},
  [FB_DP] = {"proc/dispinfo", 0, 0, dispinfo_read, invalid_write},
#include "files.h"
};

int fs_open(const char *pathname, int flags, int mode) {
  int ft_len = sizeof(file_table) / sizeof(Finfo);
  for (int i = 3; i < ft_len; i++) {
    if (strcmp(pathname, file_table[i].name) == 0) {
      file_table[i].open_offset = 0;
      return i;
    }
  }
  panic("Should not reach here, %s", pathname);
  return 0;
}

size_t fs_read(int fd, void *buf, size_t len) {
  assert(fd >= 0 && fd <= sizeof(file_table) / sizeof(Finfo));
  size_t ret = 0;
  Finfo *f = &file_table[fd];

  if (f->read != NULL) {
    return f->read(buf, 0, len);
  } else {
    // 处理长度越界
    size_t real_len = len;
    if (f->open_offset + len > f->size) {
      real_len = f->size - f->open_offset;
    }
    // 进行实际读取操作
    ret = ramdisk_read(buf, f->disk_offset + f->open_offset, real_len);
    f->open_offset +=  real_len;
  }
  return ret;
}

size_t fs_write(int fd, const void *buf, size_t len) {
  assert(fd >= 0 && fd <= sizeof(file_table) / sizeof(Finfo));
  size_t ret = 0;
  Finfo *f = &file_table[fd];

  if (f->write != NULL) {
    return f->write(buf, f->open_offset, len);
  } else {
    // 处理长度越界
    size_t real_len = len;
    if (f->open_offset + len > f->size) {
      real_len = f->size - f->open_offset;
    }
    // 进行实际写入操作
    ret = ramdisk_write(buf, f->disk_offset + f->open_offset, real_len);
    f->open_offset += real_len;
  }
  return ret;
}

size_t fs_lseek(int fd, size_t offset, int whence) {
  size_t cur_offset = file_table[fd].open_offset;

  switch (whence) {
    case SEEK_SET:
      assert(offset <= file_table[fd].size);
      file_table[fd].open_offset = offset;
      break;
    case SEEK_CUR:
      assert(cur_offset + offset <= file_table[fd].size);
      file_table[fd].open_offset = cur_offset + offset;
      break;
    case SEEK_END:
      assert(file_table[fd].size + offset <= file_table[fd].size);
      file_table[fd].open_offset =  file_table[fd].size + offset;
      break;
    default:
      assert("Invalid whence parameter\n");
    }
    return file_table[fd].open_offset;
}

int fs_close(int fd) {
  return 0;
}

void init_fs() {
  // TODO: initialize the size of /dev/fb
  file_table[FD_FB].size = io_read(AM_GPU_CONFIG).vmemsz;
  printf("FD_FB size=%d", file_table[FD_FB].size);
}
