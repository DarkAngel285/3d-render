#include "rendering.h"
#include "3d_structs.h"
#include "file_obj.h"
#include "term_tweaks.h"
#include <math.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

angle *to_rad(angle *a) {
  const double pi = 3.14159;
  return new_angle(a->x * pi / 180, a->y * pi / 180, a->z * pi / 180);
}

void draw_line(vec2i *p1, vec2i *p2, char texture, buffer *buf) {
  vec2i *d = new_vec2i(abs(p1->x - p2->x), abs(p1->y - p2->y));
  vec2i *s = new_vec2i((p1->x < p2->x) ? 1 : -1, (p1->y < p2->y) ? 1 : -1);
  int err = d->x - d->y;
  while (1) {
    if (p1->x + 1 > 0 && p1->y + 1 > 0 && p1->x + 1 < buf->cols &&
        p1->y + 1 < buf->rows) {
      buf->data[p1->y + 1][p1->x + 1] = texture;
    }
    if (p1->x == p2->x && p1->y == p2->y)
      break;
    int e2 = 2 * err;
    if (e2 > -d->y) {
      err -= d->y;
      p1->x += s->x;
    }
    if (e2 < d->x) {
      err += d->x;
      p1->y += s->y;
    }
  }
  free(d);
  free(s);
}

matrix *create_projection_matrix(angle *rot_a, vec3 *move, vec3 *scale) {
  float aspect = 20.0f / 9.0f;

  angle *rot_a_rad = to_rad(rot_a);

  matrix *s = new_matrix(4, 4,
                         (float[4][4]){{scale->x * aspect, 0, 0, 0},
                                       {0, scale->x, 0, 0},
                                       {0, 0, scale->y, 0},
                                       {0, 0, 0, 1}}),
         *rx = new_matrix(
             4, 4,
             (float[4][4]){{1, 0, 0, 0},
                           {0, cos(rot_a_rad->x), -sin(rot_a_rad->x), 0},
                           {0, sin(rot_a_rad->x), cos(rot_a_rad->x), 0},
                           {0, 0, 0, 1}}),
         *ry = new_matrix(
             4, 4,
             (float[4][4]){{cos(rot_a_rad->y), 0, sin(rot_a_rad->y), 0},
                           {0, 1, 0, 0},
                           {-sin(rot_a_rad->y), 0, cos(rot_a_rad->y), 0},
                           {0, 0, 0, 1}}),
         *rz = new_matrix(
             4, 4,
             (float[4][4]){{cos(rot_a_rad->z), -sin(rot_a_rad->z), 0, 0},
                           {sin(rot_a_rad->z), cos(rot_a_rad->z), 0, 0},
                           {0, 0, 1, 0},
                           {0, 0, 0, 1}}),
         *mv = new_matrix(4, 4,
                          (float[4][4]){{1, 0, 0, move->x},
                                        {0, 1, 0, move->y},
                                        {0, 0, 1, move->z},
                                        {0, 0, 0, 1}});

  matrix *mvs = mult_matrix(mv, s), *mvsrx = mult_matrix(mvs, rx),
         *mvsrxry = mult_matrix(mvsrx, ry),
         *projection_matrix = mult_matrix(mvsrxry, rz);

  free(rot_a_rad);
  free_matrix(s);
  free_matrix(rx);
  free_matrix(ry);
  free_matrix(rz);
  free_matrix(mv);
  free_matrix(mvs);
  free_matrix(mvsrx);
  free_matrix(mvsrxry);
  return projection_matrix;
}

void draw(vertices *vs, faces *fs, angle *rot_a, vec3 *move, vec3 *scale) {
  struct winsize w;
  ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
  buffer *buf = new_buffer(w.ws_row + 1, w.ws_col + 1);

  matrix *projection_matrix = create_projection_matrix(rot_a, move, scale);

  for (int i = 0; i < fs->size; ++i) {
    for (int j = 0; j < fs->data[i]->size; ++j) {
      vec4 *t1 = vec3_to_vec4(vs->data[fs->data[i]->data[j] - 1], 1),
           *t2 = vec3_to_vec4(
               vs->data[fs->data[i]
                            ->data[j == fs->data[i]->size - 1 ? 0 : j + 1] -
                        1],
               1);

      vec4 *new_t1 = mult_matrix_vec4(projection_matrix, t1),
           *new_t2 = mult_matrix_vec4(projection_matrix, t2);

      free(t1);
      free(t2);

      t1 = new_t1;
      t2 = new_t2;

      vec2i *p1 = new_vec2i(buf->cols / 2.0f + t1->x, buf->rows / 2.0f - t1->y),
            *p2 = new_vec2i(buf->cols / 2.0f + t2->x, buf->rows / 2.0f - t2->y);

      draw_line(p1, p2, '*', buf);

      free(t1);
      free(t2);
      free(p1);
      free(p2);
    }
  }

  draw_buffer(buf);

  free_buffer(buf);
  free_matrix(projection_matrix);
}

void render(char *filename) {
  vertices *vs = new_vertices();
  faces *fs = new_faces();
  read_obj(filename, vs, fs);

  char buf[3];
  int development = 0, rotate = 0, x = 0, y = 0, z = 0;
  vec3 *scale = new_vec3(10, 10, 10), *move = new_vec3(0, 0, 0),
       *upscale = new_vec3(0.75f, 0.75f, 0.75f),
       *downscale = new_vec3(-0.75f, -0.75f, -0.75f);
  angle *rot_a = new_angle(0, 0, 0);
  while (1) {
    int bytes_read = read(STDIN_FILENO, &buf, 3);
    if (bytes_read) {
      if (buf[0] == 'q') {
        break;
      } else if (buf[0] == '\x1b' && buf[1] == '[') {
        switch (buf[2]) {
        case 'A':
          rot_a->x += 3;
          if (rot_a->x >= 360)
            rot_a->x = 0;
          break;
        case 'B':
          rot_a->x -= 3;
          if (rot_a->x < 0)
            rot_a->x = 360;
          break;
        case 'C':
          rot_a->y += 3;
          if (rot_a->y >= 360)
            rot_a->y = 0;
          break;
        case 'D':
          rot_a->y -= 3;
          if (rot_a->y < 0)
            rot_a->y = 360;
          break;
        }
      } else if (buf[0] == '+' || buf[0] == '=') {
        vec3 *new_scale = sum_vec3(scale, upscale);
        free(scale);
        scale = new_scale;
        if (scale->x > 100)
          scale->x = 100;
        if (scale->y > 100)
          scale->y = 100;
        if (scale->z > 100)
          scale->z = 100;
      } else if (buf[0] == '-' || buf[0] == '_') {
        vec3 *new_scale = sum_vec3(scale, downscale);
        free(scale);
        scale = new_scale;
        if (scale->x < 0)
          scale->x = 0;
        if (scale->y < 0)
          scale->y = 0;
        if (scale->z < 0)
          scale->z = 0;
      } else if (buf[0] == 'r') {
        rotate = !rotate;
      } else if (buf[0] == 'x') {
        x = !x;
      } else if (buf[0] == 'y') {
        y = !y;
      } else if (buf[0] == 'z') {
        z = !z;
      } else if (buf[0] == 'D') {
        development = !development;
      } else if (buf[0] == '0') {
        *rot_a = (angle){0, 0, 0};
        *move = (vec3){0, 0, 0};
      } else if (buf[0] == 'w') {
        move->y += 1;
        if (move->y > 100)
          move->y = 100;
      } else if (buf[0] == 's') {
        move->y -= 1;
        if (move->y < -100)
          move->y = -100;
      } else if (buf[0] == 'd') {
        move->x += 1;
        if (move->x > 100)
          move->x = 100;
      } else if (buf[0] == 'a') {
        move->x -= 1;
        if (move->x < -100)
          move->x = -100;
      } else if (buf[0] == '>') {
        move->z += 1;
        if (move->z > 100)
          move->z = 100;
      } else if (buf[0] == '<') {
        move->z -= 1;
        if (move->z < -100)
          move->z = -100;
      }
    }
    clear();
    if (rotate) {
      if (x) {
        rot_a->x += 3;
        if (rot_a->x > 360)
          rot_a->x = 0;
      }
      if (y) {
        rot_a->y += 3;
        if (rot_a->y > 360)
          rot_a->y = 0;
      }
      if (z) {
        rot_a->z += 3;
        if (rot_a->z > 360)
          rot_a->z = 0;
      }
    }
    draw(vs, fs, rot_a, move, scale);
    if (development) {
      gotoxy(1, 1);
      printf("%f %f %f", rot_a->x, rot_a->y, rot_a->z);
      gotoxy(1, 2);
      printf("%f %f %f", scale->x, scale->y, scale->z);
      gotoxy(1, 3);
      printf("%f %f %f", move->x, move->y, move->z);
      gotoxy(1, 4);
      printf("rotate:%d", rotate);
      gotoxy(1, 5);
      printf("x:%d y:%d z:%d", x, y, z);
    }
    fflush(stdout);
    usleep(2e4);
  }
  free(scale);
  free(move);
  free(upscale);
  free(downscale);
  free(rot_a);
  free_vertices(vs);
  free_faces(fs);
}
