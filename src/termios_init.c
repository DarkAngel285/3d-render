#include "termios_init.h"
#include "term_tweaks.h"
#include <stdio.h>
#include <unistd.h>

void init(struct termios *old_t, struct termios *new_t) {
  tcgetattr(STDIN_FILENO, old_t);
  *new_t = *old_t;
  new_t->c_lflag &= ~(ICANON | ECHO);
  new_t->c_cc[VMIN] = 0;
  new_t->c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, new_t);
  clear();
  curhide(1);
  fflush(stdout);
}

void deinit(struct termios *old_t) {
  tcsetattr(STDIN_FILENO, TCSANOW, old_t);
  clear();
  curhide(0);
  fflush(stdout);
}
