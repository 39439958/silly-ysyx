#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[], char *envp[]);

extern char **environ;
int argc;
char **argv;
char **envp;

void call_main(uintptr_t *args) {
  argc = (int)(*args);
  argv = args + 1;
  envp = args + argc + 2;
  environ = envp;
  exit(main(argc, argv, envp));
  assert(0);
}
