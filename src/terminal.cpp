#include "terminal.hpp"
#include <iostream>
#include <termios.h>
#include <unistd.h>

struct termios old_t;

namespace terminal {
void disable_raw_mode() {
  tcsetattr(STDIN_FILENO, TCSANOW, &old_t);
  std::cout << curshow << clr << std::flush;
}

void enable_raw_mode() {
  tcgetattr(STDIN_FILENO, &old_t);
  struct termios new_t = old_t;
  cfmakeraw(&new_t);
  new_t.c_cc[VMIN] = 0;
  new_t.c_cc[VTIME] = 1;
  tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
  std::cout << curhide << clr << std::flush;
}
} // namespace terminal
