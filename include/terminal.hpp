#ifndef __TERMINAL_HPP__
#define __TERMINAL_HPP__

#define clr "\x1b[H\x1b[J"
#define curmov(row, col) "\x1b[" << row + 1 << ";" << col + 1 << "H"
#define curhide "\e[?25l"
#define curshow "\e[?25h"

namespace terminal {
void enable_raw_mode();
void disable_raw_mode();
} // namespace terminal

#endif
