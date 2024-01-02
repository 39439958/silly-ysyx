#include <NDL.h>
#include <SDL.h>

#define keyname(k) #k,

static const char *keyname[] = {
  "NONE",
  _KEYS(keyname)
};

static int key_state[83];

int SDL_PushEvent(SDL_Event *ev) {
  return 0;
}

int SDL_PollEvent(SDL_Event *ev) {
  char buf[64];
  if (NDL_PollEvent(buf, 0) == 0) {
    return 0;
  }
  char type[8], key_name[8];
  int keycode;
  sscanf(buf, "%s %s %d\n", type, key_name, &keycode);
  if (strcmp(type, "kd") == 0) {
    ev->type = SDL_KEYDOWN;
    ev->key.keysym.sym = keycode;
    key_state[keycode] = 1;
  } else {
    ev->type = SDL_KEYUP;
    ev->key.keysym.sym = keycode;
    key_state[keycode] = 0;
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
    key_state[keycode] = 1;
  } else {
    event->type = SDL_KEYUP;
    event->key.keysym.sym = keycode;
    key_state[keycode] = 0;
  }
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t* SDL_GetKeyState(int *numkeys) {
  if (numkeys) *numkeys = 83;
  return key_state;
}
