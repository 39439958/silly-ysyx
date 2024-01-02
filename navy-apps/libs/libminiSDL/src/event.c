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
  char buf[64];
  NDL_PollEvent(buf, 0);
  if (buf == NULL) {
    return 0;
  }
  char type[8], key_name[8];
  int keycode;
  sscanf(buf, "%s %s %d\n", type, key_name, &keycode);
  if (strcmp(type, "kd") == 0) {
    ev->type = SDL_KEYDOWN;
    ev->key.keysym.sym = keycode;
  } else {
    ev->type = SDL_KEYUP;
    ev->key.keysym.sym = keycode;
  }
  return 1;
}

int SDL_WaitEvent(SDL_Event *event) {
  char buf[64];
  NDL_PollEvent(buf, 0);
  char type[8], key_name[8];
  int keycode;
  sscanf(buf, "%s %s %d\n", type, key_name, &keycode);
  if (strcmp(type, "kd") == 0) {
    event->type = SDL_KEYDOWN;
    event->key.keysym.sym = keycode;
  } else {
    event->type = SDL_KEYUP;
    event->key.keysym.sym = keycode;
  }
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t* SDL_GetKeyState(int *numkeys) {
  return NULL;
}
