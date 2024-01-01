#include <NDL.h>
#include <SDL.h>

#define keyname(k) #k,

static const char *keyname[] = {
  "NONE",
  _KEYS(keyname)
};

int SDL_PushEvent(SDL_Event *ev) {
  return 0;
}

int SDL_PollEvent(SDL_Event *ev) {
  return 0;
}

int SDL_WaitEvent(SDL_Event *event) {
  char buf[64];
  NDL_PollEvent(buf, 0);
  char type[8], key_name[8];
  int keycode;
 // sscanf(buf, "%s %s %d\n", type, key_name, );
  
  if (strcmp(type, "kd") == 0) {
    event->type = SDL_KEYDOWN;
  } else {
    event->type = SDL_KEYUP;
  }
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t* SDL_GetKeyState(int *numkeys) {
  return NULL;
}
