#ifndef __TERMIOS_INIT_H__
#define __TERMIOS_INIT_H__

#include <termios.h>

void init(struct termios *old_t, struct termios *new_t);

void deinit(struct termios *old_t);

#endif
