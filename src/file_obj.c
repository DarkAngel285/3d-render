#include "file_obj.h"
#include <stdio.h>

void read_obj(char *filename, vertices *vs, faces *fs) {
  FILE *file = fopen(filename, "r");

  char buf[1024];
  while (fgets(buf, sizeof(buf), file)) {
    if (buf[0] == 'v' && buf[1] == ' ') {
      vec3 *v = new_vec3(0, 0, 0);
      sscanf(buf, "v %f %f %f\n", &v->x, &v->y, &v->z);
      add_vertex(vs, v);
    } else if (buf[0] == 'f' && buf[1] == ' ') {
      face *f = new_face();
      int v_begin = 0;
      int fi = 0;
      for (int i = 1; buf[i] != '\0' && i < 1024; ++i) {
        if (buf[i] == ' ') {
          if (v_begin) {
            add_to_face(f, fi);
            fi = 0;
          } else {
            v_begin = 1;
          }
        } else if (v_begin && buf[i] >= '0' && buf[i] - '0' < 10) {
          fi *= 10;
          fi += buf[i] - '0';
        } else if (v_begin) {
          add_to_face(f, fi);
          fi = 0;
          v_begin = 0;
        }
      }
      add_face(fs, f);
    }
  }

  fclose(file);
}
