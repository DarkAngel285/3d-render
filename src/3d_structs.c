#include "3d_structs.h"
#include <stdio.h>

/* --- Vectors methods --- */

vec2 *new_vec2(float x, float y) {
  vec2 *new_vec2 = (vec2 *)malloc(sizeof(vec2));
  *new_vec2 = (vec2){x, y};
  return new_vec2;
}

vec2i *new_vec2i(int x, int y) {
  vec2i *new_vec2i = (vec2i *)malloc(sizeof(vec2i));
  *new_vec2i = (vec2i){x, y};
  return new_vec2i;
}

vec3 *new_vec3(float x, float y, float z) {
  vec3 *new_vec3 = (vec3 *)malloc(sizeof(vec3));
  *new_vec3 = (vec3){x, y, z};
  return new_vec3;
}

vec3i *new_vec3i(int x, int y, int z) {
  vec3i *new_vec3i = (vec3i *)malloc(sizeof(vec3i));
  *new_vec3i = (vec3i){x, y, z};
  return new_vec3i;
}

vec4 *new_vec4(float x, float y, float z, float w) {
  vec4 *new_vec4 = (vec4 *)malloc(sizeof(vec4));
  *new_vec4 = (vec4){x, y, z, w};
  return new_vec4;
}

vec4i *new_vec4i(int x, int y, int z, int w) {
  vec4i *new_vec4i = (vec4i *)malloc(sizeof(vec4i));
  *new_vec4i = (vec4i){x, y, z, w};
  return new_vec4i;
}

/* --- Angle methods --- */

angle *new_angle(double x, double y, double z) {
  angle *new_angle = (angle *)malloc(sizeof(angle));
  *new_angle = (angle){x, y, z};
  return new_angle;
}

/* --- Matrix methods --- */

matrix *new_empty_matrix(size_t rows, size_t cols) {
  matrix *new_matrix = (matrix *)malloc(sizeof(matrix));
  *new_matrix = (matrix){rows, cols, (float **)malloc(rows * sizeof(float *))};
  for (size_t i = 0; i < rows; ++i)
    new_matrix->data[i] = (float *)calloc(cols, sizeof(float));
  return new_matrix;
}

matrix *new_matrix(size_t rows, size_t cols, float data[rows][cols]) {
  matrix *new_matrix = (matrix *)malloc(sizeof(matrix));
  *new_matrix = (matrix){rows, cols, (float **)malloc(rows * sizeof(float *))};
  for (size_t i = 0; i < rows; ++i) {
    new_matrix->data[i] = (float *)malloc(cols * sizeof(float));
    for (size_t j = 0; j < cols; ++j)
      new_matrix->data[i][j] = data[i][j];
  }
  return new_matrix;
}

void free_matrix(matrix *m) {
  for (size_t i = 0; i < m->rows; ++i)
    free(m->data[i]);
  free(m->data);
  free(m);
}

/* --- Vertices methods --- */

vertices *new_vertices() {
  vertices *new_vertices = (vertices *)malloc(sizeof(vertices));
  *new_vertices = (vertices){0, NULL};
  return new_vertices;
}

void free_vertices(vertices *vs) {
  for (size_t i = 0; i < vs->size; ++i)
    free(vs->data[i]);
  free(vs->data);
  free(vs);
}

void add_vertex(vertices *vs, vec3 *v) {
  vs->data = (vec3 **)realloc(vs->data, ++vs->size * sizeof(vec3 *));
  vs->data[vs->size - 1] = v;
}

/* --- Face methods --- */

face *new_face() {
  face *new_face = (face *)malloc(sizeof(face));
  *new_face = (face){0, NULL};
  return new_face;
}

void free_face(face *f) {
  free(f->data);
  free(f);
}

void add_to_face(face *f, int i) {
  f->data = (int *)realloc(f->data, ++f->size * sizeof(int));
  f->data[f->size - 1] = i;
}

/* --- Faces methods --- */

faces *new_faces() {
  faces *new_faces = (faces *)malloc(sizeof(faces));
  *new_faces = (faces){0, NULL};
  return new_faces;
}

void free_faces(faces *fs) {
  for (size_t i = 0; i < fs->size; ++i)
    free_face(fs->data[i]);
  free(fs->data);
  free(fs);
}

void add_face(faces *fs, face *f) {
  fs->data = (face **)realloc(fs->data, ++fs->size * sizeof(face *));
  fs->data[fs->size - 1] = f;
}
