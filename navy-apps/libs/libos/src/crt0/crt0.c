#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]);
extern char **environ;
void call_main(uintptr_t *args) {
  int argc = (int)args[0];
  char **argv = (char **)(args + 1);

  char **envp = (char **)(args + argc + 2);
  environ = envp;
  exit(main(argc, argv, envp));

  printf("%s\n", argv[0]);

  // char *empty[] = {NULL};
  // environ = empty;
  // exit(main(0, empty, empty));
  assert(0);
}
