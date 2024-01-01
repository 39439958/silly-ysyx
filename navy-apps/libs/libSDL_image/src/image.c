#define SDL_malloc  malloc
#define SDL_free    free
#define SDL_realloc realloc

#define SDL_STBIMAGE_IMPLEMENTATION
#include "SDL_stbimage.h"

SDL_Surface* IMG_Load_RW(SDL_RWops *src, int freesrc) {
  assert(src->type == RW_TYPE_MEM);
  assert(freesrc == 0);
  return NULL;
}

SDL_Surface* IMG_Load(const char *filename) {
  // int fd = open(filename, 0, 0);
  // int size = lseek(fd, 0, SEEK_END);
  // void *buf = malloc(size);
  // lseek(fd, 0, SEEK_SET);
  // read(fd, buf, size);
  // SDL_Surface *surface = STBIMG_LoadFromMemory((char *)buf, size);
  // free(buf);
  // close(fd);
  // return surface;
  FILE *fp = fopen(filename, "r");
  if (!fp) return NULL;

  long file_size = 0;
  long cur_offset = ftell(fp);

  fseek(fp, 0, SEEK_END);

  file_size = ftell(fp);

  fseek(fp, cur_offset, SEEK_SET);
  
  char buf[file_size];
  fread(buf, 1, file_size, fp);
  SDL_Surface *ret = STBIMG_LoadFromMemory((char *)buf, file_size);

  free(buf);
  fclose(fp);
  return ret;
}

int IMG_isPNG(SDL_RWops *src) {
  return 0;
}

SDL_Surface* IMG_LoadJPG_RW(SDL_RWops *src) {
  return IMG_Load_RW(src, 0);
}

char *IMG_GetError() {
  return "Navy does not support IMG_GetError()";
}
