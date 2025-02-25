#include "term_tweaks.h"

buffer *new_buffer(size_t rows, size_t cols) {
  buffer *buf = (buffer *)malloc(sizeof(buffer));
  *buf = (buffer){rows, cols, (char **)malloc(rows * sizeof(char *))};
  for (int i = 0; i < rows; ++i)
    buf->data[i] = (char *)calloc(cols, sizeof(char));
  return buf;
}

void draw_buffer(buffer *buf) {
  for (int i = 0; i < buf->rows; ++i)
    for (int j = 0; j < buf->cols; ++j) {
      if (buf->data[i][j] != '\0') {
        gotoxy(j, i);
        printf("%c", buf->data[i][j]);
      }
    }
}

void free_buffer(buffer *buf) {
  for (int i = 0; i < buf->rows; ++i) {
    free(buf->data[i]);
  }
  free(buf->data);
  free(buf);
}
