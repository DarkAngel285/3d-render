#include "3d_structs.h"
#include <stdio.h>

matrix *new_matrix(size_t rows, size_t cols, float data[rows][cols]) {
  matrix *m = (matrix *)malloc(sizeof(matrix));
  *m = (matrix){rows, cols, (float **)malloc(rows * sizeof(float *))};
  for (int i = 0; i < rows; ++i) {
    m->data[i] = (float *)malloc(cols * sizeof(float));
    for (int j = 0; j < cols; ++j)
      m->data[i][j] = data[i][j];
  }
  return m;
}

void add_vertex(vertices *vs, vec3 v) {
  vs->data = (vec3 *)realloc(vs->data, ++(vs->size) * sizeof(vec3));
  vs->data[vs->size - 1] = v;
}

void add_face(face *f, int i) {
  f->data = (int *)realloc(f->data, ++(f->size) * sizeof(int));
  f->data[f->size - 1] = i;
}

void add_faces(faces *fs, face *f) {
  fs->data = (face **)realloc(fs->data, ++(fs->size) * sizeof(face *));
  fs->data[fs->size - 1] = f;
}

matrix *mult_matrix(matrix *a, matrix *b) {
  if (a->cols != b->rows) {
    matrix *m = (matrix *)malloc(sizeof(matrix));
    *m = (matrix){0, 0, NULL};
    return m;
  }
  matrix *m = (matrix *)malloc(sizeof(matrix));
  *m = (matrix){a->rows, b->cols, (float **)malloc(a->rows * sizeof(float *))};
  for (int i = 0; i < m->rows; ++i) {
    m->data[i] = (float *)malloc(m->cols * sizeof(float));
    for (int j = 0; j < m->cols; ++j) {
      m->data[i][j] = 0.0f;
      for (int k = 0; k < a->cols; ++k) {
        m->data[i][j] += a->data[i][k] * b->data[k][j];
      }
    }
  }
  return m;
}

vec2 mult_matrix_vec2(matrix *a, vec2 b) {
  if (a->rows >= 2 && a->cols >= 2)
    return (vec2){b.x * a->data[0][0] + b.y * a->data[0][1],
                  b.x * a->data[1][0] + b.y * a->data[1][1]};
  return (vec2){0, 0};
}

vec2i mult_matrix_vec2i(matrix *a, vec2i b) {
  if (a->rows >= 2 && a->cols >= 2)
    return (vec2i){b.x * a->data[0][0] + b.y * a->data[0][1],
                   b.x * a->data[1][0] + b.y * a->data[1][1]};
  return (vec2i){0, 0};
}

vec3 mult_matrix_vec3(matrix *a, vec3 b) {
  if (a->rows >= 3 && a->cols >= 3)
    return (vec3){
        b.x * a->data[0][0] + b.y * a->data[0][1] + b.z * a->data[0][2],
        b.x * a->data[1][0] + b.y * a->data[1][1] + b.z * a->data[1][2],
        b.x * a->data[2][0] + b.y * a->data[2][1] + b.z * a->data[2][2]};
  return (vec3){0, 0, 0};
}

vec3i mult_matrix_vec3i(matrix *a, vec3i b) {
  if (a->rows >= 3 && a->cols >= 3)
    return (vec3i){
        b.x * a->data[0][0] + b.y * a->data[0][1] + b.z * a->data[0][2],
        b.x * a->data[1][0] + b.y * a->data[1][1] + b.z * a->data[1][2],
        b.x * a->data[2][0] + b.y * a->data[2][1] + b.z * a->data[2][2]};
  return (vec3i){0, 0, 0};
}

vec4 mult_matrix_vec4(matrix *a, vec4 b) {
  if (a->rows >= 4 && a->cols >= 4)
    return (vec4){b.x * a->data[0][0] + b.y * a->data[0][1] +
                      b.z * a->data[0][2] + b.w * a->data[0][3],
                  b.x * a->data[1][0] + b.y * a->data[1][1] +
                      b.z * a->data[1][2] + b.w * a->data[1][3],
                  b.x * a->data[2][0] + b.y * a->data[2][1] +
                      b.z * a->data[2][2] + b.w * a->data[2][3],
                  b.x * a->data[3][0] + b.y * a->data[3][1] +
                      b.z * a->data[3][2] + b.w * a->data[3][3]};
  return (vec4){0, 0, 0, 0};
}

vec4i mult_matrix_vec4i(matrix *a, vec4i b) {
  if (a->rows >= 4 && a->cols >= 4)
    return (vec4i){b.x * a->data[0][0] + b.y * a->data[0][1] +
                       b.z * a->data[0][2] + b.w * a->data[0][3],
                   b.x * a->data[1][0] + b.y * a->data[1][1] +
                       b.z * a->data[1][2] + b.w * a->data[1][3],
                   b.x * a->data[2][0] + b.y * a->data[2][1] +
                       b.z * a->data[2][2] + b.w * a->data[2][3],
                   b.x * a->data[3][0] + b.y * a->data[3][1] +
                       b.z * a->data[3][2] + b.w * a->data[3][3]};
  return (vec4i){0, 0, 0, 0};
}

vec2 mult_vec2(vec2 a, vec2 b) { return (vec2){a.x * b.x, a.y * b.y}; }

vec2 mult_vec2_vec3(vec2 a, vec3 b) { return (vec2){a.x * b.x, a.y * b.y}; }

vec2 mult_vec2_vec4(vec2 a, vec4 b) { return (vec2){a.x * b.x, a.y * b.y}; }

vec2i mult_vec2i(vec2i a, vec2i b) { return (vec2i){a.x * b.x, a.y * b.y}; }

vec2i mult_vec2i_vec3i(vec2i a, vec3i b) {
  return (vec2i){a.x * b.x, a.y * b.y};
}

vec2i mult_vec2i_vec4i(vec2i a, vec4i b) {
  return (vec2i){a.x * b.x, a.y * b.y};
}

vec3 mult_vec3(vec3 a, vec3 b) {
  return (vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

vec3 mult_vec3_vec2(vec3 a, vec2 b) {
  return (vec3){a.x * b.x, a.y * b.y, a.z};
}

vec3 mult_vec3_vec4(vec3 a, vec4 b) {
  return (vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

vec3i mult_vec3i(vec3i a, vec3i b) {
  return (vec3i){a.x * b.x, a.y * b.y, a.z * b.z};
}

vec3i mult_vec3i_vec2i(vec3i a, vec2i b) {
  return (vec3i){a.x * b.x, a.y * b.y, a.z};
}

vec3i mult_vec3i_vec4i(vec3i a, vec4i b) {
  return (vec3i){a.x * b.x, a.y * b.y, a.z * b.z};
}

vec4 mult_vec4(vec4 a, vec4 b) {
  return (vec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

vec4 mult_vec4_vec2(vec4 a, vec2 b) {
  return (vec4){a.x * b.x, a.y * b.y, a.z, a.w};
}

vec4 mult_vec4_vec3(vec4 a, vec3 b) {
  return (vec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w};
}

vec4i mult_vec4i(vec4i a, vec4i b) {
  return (vec4i){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

vec4i mult_vec4i_vec2i(vec4i a, vec2i b) {
  return (vec4i){a.x * b.x, a.y * b.y, a.z, a.w};
}

vec4i mult_vec4i_vec3i(vec4i a, vec3i b) {
  return (vec4i){a.x * b.x, a.y * b.y, a.z * b.z, a.w};
}

vec4 sum_vec4(vec4 a, vec4 b) {
  return (vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

vec4 sum_vec4_vec2(vec4 a, vec2 b) {
  return (vec4){a.x + b.x, a.y + b.y, a.z, a.w};
}

vec4 sum_vec4_vec3(vec4 a, vec3 b) {
  return (vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w};
}

vec4i sum_vec4i(vec4i a, vec4i b) {
  return (vec4i){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

vec4i sum_vec4i_vec2i(vec4i a, vec2i b) {
  return (vec4i){a.x + b.x, a.y + b.y, a.z, a.w};
}

vec4i sum_vec4i_vec3i(vec4i a, vec3i b) {
  return (vec4i){a.x + b.x, a.y + b.y, a.z + b.z, a.w};
}

vec3 sum_vec3(vec3 a, vec3 b) {
  return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 sum_vec3_vec2(vec3 a, vec2 b) { return (vec3){a.x + b.x, a.y + b.y, a.z}; }

vec3 sum_vec3_vec4(vec3 a, vec4 b) {
  return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3i sum_vec3i(vec3i a, vec3i b) {
  return (vec3i){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3i sum_vec3i_vec2i(vec3i a, vec2i b) {
  return (vec3i){a.x + b.x, a.y + b.y, a.z};
}

vec3i sum_vec3i_vec4i(vec3i a, vec4i b) {
  return (vec3i){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec2 sum_vec2(vec2 a, vec2 b) { return (vec2){a.x + b.x, a.y + b.y}; }

vec2 sum_vec2_vec3(vec2 a, vec3 b) { return (vec2){a.x + b.x, a.y + b.y}; }

vec2 sum_vec2_vec4(vec2 a, vec4 b) { return (vec2){a.x + b.x, a.y + b.y}; }

vec2i sum_vec2i(vec2i a, vec2i b) { return (vec2i){a.x + b.x, a.y + b.y}; }

vec2i sum_vec2i_vec3i(vec2i a, vec3i b) {
  return (vec2i){a.x + b.x, a.y + b.y};
}

vec2i sum_vec2i_vec4i(vec2i a, vec4i b) {
  return (vec2i){a.x + b.x, a.y + b.y};
}

vec4 diff_vec4(vec4 a, vec4 b) {
  return (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

vec4 diff_vec4_vec2(vec4 a, vec2 b) {
  return (vec4){a.x - b.x, a.y - b.y, a.z, a.w};
}

vec4 diff_vec4_vec3(vec4 a, vec3 b) {
  return (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w};
}

vec4i diff_vec4i(vec4i a, vec4i b) {
  return (vec4i){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

vec4i diff_vec4i_vec2i(vec4i a, vec2i b) {
  return (vec4i){a.x - b.x, a.y - b.y, a.z, a.w};
}

vec4i diff_vec4i_vec3i(vec4i a, vec3i b) {
  return (vec4i){a.x - b.x, a.y - b.y, a.z - b.z, a.w};
}

vec3 diff_vec3(vec3 a, vec3 b) {
  return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3 diff_vec3_vec2(vec3 a, vec2 b) {
  return (vec3){a.x - b.x, a.y - b.y, a.z};
}

vec3 diff_vec3_vec4(vec3 a, vec4 b) {
  return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3i diff_vec3i(vec3i a, vec3i b) {
  return (vec3i){a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3i diff_vec3i_vec2i(vec3i a, vec2i b) {
  return (vec3i){a.x - b.x, a.y - b.y, a.z};
}

vec3i diff_vec3i_vec4i(vec3i a, vec4i b) {
  return (vec3i){a.x - b.x, a.y - b.y, a.z - b.z};
}

vec2 diff_vec2(vec2 a, vec2 b) { return (vec2){a.x - b.x, a.y - b.y}; }

vec2 diff_vec2_vec3(vec2 a, vec3 b) { return (vec2){a.x - b.x, a.y - b.y}; }

vec2 diff_vec2_vec4(vec2 a, vec4 b) { return (vec2){a.x - b.x, a.y - b.y}; }

vec2i diff_vec2i(vec2i a, vec2i b) { return (vec2i){a.x - b.x, a.y - b.y}; }

vec2i diff_vec2i_vec3i(vec2i a, vec3i b) {
  return (vec2i){a.x - b.x, a.y - b.y};
}

vec2i diff_vec2i_vec4i(vec2i a, vec4i b) {
  return (vec2i){a.x - b.x, a.y - b.y};
}

vec2 vec3_to_vec2(vec3 a) { return (vec2){a.x, a.y}; }

vec2 vec3i_to_vec2(vec3i a) { return (vec2){a.x, a.y}; }

vec2i vec3_to_vec2i(vec3 a) { return (vec2i){a.x, a.y}; }

vec2 vec4_to_vec2(vec4 a) { return (vec2){a.x, a.y}; }

vec2 vec4i_to_vec2(vec4i a) { return (vec2){a.x, a.y}; }

vec2i vec4_to_vec2i(vec4 a) { return (vec2i){a.x, a.y}; }

vec3 vec2_to_vec3(vec2 a, float z) { return (vec3){a.x, a.y, z}; }

vec3 vec2i_to_vec3(vec2i a, float z) { return (vec3){a.x, a.y, z}; }

vec3i vec2_to_vec3i(vec2 a, int z) { return (vec3i){a.x, a.y, z}; }

vec3 vec4_to_vec3(vec4 a) { return (vec3){a.x, a.y, a.z}; }

vec3 vec4i_to_vec3(vec4i a) { return (vec3){a.x, a.y, a.z}; }

vec3i vec4_to_vec3i(vec4 a) { return (vec3i){a.x, a.y, a.z}; }

vec4 vec2_to_vec4(vec2 a, float z, float w) { return (vec4){a.x, a.y, z, w}; }

vec4 vec2i_to_vec4(vec2i a, float z, float w) { return (vec4){a.x, a.y, z, w}; }

vec4i vec2_to_vec4i(vec2 a, int z, int w) { return (vec4i){a.x, a.y, z, w}; }

vec4 vec3_to_vec4(vec3 a, float w) { return (vec4){a.x, a.y, a.z, w}; }

vec4 vec3i_to_vec4(vec3i a, float w) { return (vec4){a.x, a.y, a.z, w}; }

vec4i vec3_to_vec4i(vec3 a, int w) { return (vec4i){a.x, a.y, a.z, w}; }

vec2 vec2i_to_vec2(vec2i a) { return (vec2){a.x, a.y}; }

vec2i vec2_to_vec2i(vec2 a) { return (vec2i){a.x, a.y}; }

vec3 vec3i_to_vec3(vec3i a) { return (vec3){a.x, a.y, a.z}; }

vec3i vec3_to_vec3i(vec3 a) { return (vec3i){a.x, a.y, a.z}; }

vec4 vec4i_to_vec4(vec4i a) { return (vec4){a.x, a.y, a.z, a.w}; }

vec4i vec4_to_vec4i(vec4 a) { return (vec4i){a.x, a.y, a.z, a.w}; }

void free_matrix(matrix *m) {
  for (int i = 0; i < m->rows; ++i)
    free(m->data[i]);
  free(m->data);
  free(m);
}

void free_face(face *f) {
  free(f->data);
  free(f);
}

void free_faces(faces *fs) {
  for (int i = 0; i < fs->size; ++i)
    free_face(fs->data[i]);
  free(fs->data);
  free(fs);
}

void free_vertices(vertices *vs) {
  free(vs->data);
  free(vs);
}
