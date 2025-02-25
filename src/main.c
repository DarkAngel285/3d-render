#include "rendering.h"
#include "termios_init.h"

int main(int argc, char **argv) {
  struct termios old_t, new_t;
  init(&old_t, &new_t);
  if (argc == 2)
    render(argv[1]);
  deinit(&old_t);
  return 0;
}
