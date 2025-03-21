#ifndef __TERM_TWEAKS_H__
#define __TERM_TWEAKS_H__

#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\x1b[H\x1b[J")
#define gotoxy(x, y) printf("\x1b[%d;%dH", y, x)
#define curhide(i) printf(i ? "\e[?25l" : "\e[?25h")

typedef struct {
  size_t rows, cols;
  char **data;
  int **depth;
} buffer;

buffer *new_buffer(size_t rows, size_t cols);

void draw_buffer(buffer *buf);

void free_buffer(buffer *buf);

#endif
