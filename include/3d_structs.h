#ifndef __3D_STRUCTS_H__
#define __3D_STRUCTS_H__

#include <stdlib.h>

typedef struct {
  size_t rows, cols;
  float **data;
} matrix;

typedef struct {
  float x, y;
} vec2;

typedef struct {
  int x, y;
} vec2i;

typedef struct {
  float x, y, z;
} vec3;

typedef struct {
  int x, y, z;
} vec3i;

typedef struct {
  float x, y, z, w;
} vec4;

typedef struct {
  int x, y, z, w;
} vec4i;

typedef struct {
  double x, y, z;
} angle;

typedef struct {
  vec3 *data;
  size_t size;
} vertices;

typedef struct {
  int *data;
  size_t size;
} face;

typedef struct {
  face **data;
  size_t size;
} faces;

matrix *new_matrix(size_t rows, size_t cols, float data[rows][cols]);

void add_vertex(vertices *vs, vec3 v);

void add_face(face *f, int i);
void add_faces(faces *fs, face *f);

matrix *mult_matrix(matrix *a, matrix *b);
vec2 mult_matrix_vec2(matrix *a, vec2 b);
vec3 mult_matrix_vec3(matrix *a, vec3 b);
vec4 mult_matrix_vec4(matrix *a, vec4 b);

vec2 mult_vec2(vec2 a, vec2 b);
vec2 mult_vec2_vec3(vec2 a, vec3 b);
vec2 mult_vec2_vec4(vec2 a, vec4 b);
vec2i mult_vec2i(vec2i a, vec2i b);
vec2i mult_vec2i_vec3i(vec2i a, vec3i b);
vec2i mult_vec2i_vec4i(vec2i a, vec4i b);

vec3 mult_vec3(vec3 a, vec3 b);
vec3 mult_vec3_vec2(vec3 a, vec2 b);
vec3 mult_vec3_vec4(vec3 a, vec4 b);
vec3i mult_vec3i(vec3i a, vec3i b);
vec3i mult_vec3i_vec2i(vec3i a, vec2i b);
vec3i mult_vec3i_vec4i(vec3i a, vec4i b);

vec4 mult_vec4(vec4 a, vec4 b);
vec4 mult_vec4_vec2(vec4 a, vec2 b);
vec4 mult_vec4_vec3(vec4 a, vec3 b);
vec4i mult_vec4i(vec4i a, vec4i b);
vec4i mult_vec4i_vec2i(vec4i a, vec2i b);
vec4i mult_vec4i_vec3i(vec4i a, vec3i b);

vec2 sum_vec2(vec2 a, vec2 b);
vec2 sum_vec2_vec3(vec2 a, vec3 b);
vec2 sum_vec2_vec4(vec2 a, vec4 b);
vec2i sum_vec2i(vec2i a, vec2i b);
vec2i sum_vec2i_vec3i(vec2i a, vec3i b);
vec2i sum_vec2i_vec4i(vec2i a, vec4i b);

vec3 sum_vec3(vec3 a, vec3 b);
vec3 sum_vec3_vec2(vec3 a, vec2 b);
vec3 sum_vec3_vec4(vec3 a, vec4 b);
vec3i sum_vec3i(vec3i a, vec3i b);
vec3i sum_vec3i_vec2i(vec3i a, vec2i b);
vec3i sum_vec3i_vec4i(vec3i a, vec4i b);

vec4 sum_vec4(vec4 a, vec4 b);
vec4 sum_vec4_vec2(vec4 a, vec2 b);
vec4 sum_vec4_vec3(vec4 a, vec3 b);
vec4i sum_vec4i(vec4i a, vec4i b);
vec4i sum_vec4i_vec2i(vec4i a, vec2i b);
vec4i sum_vec4i_vec3i(vec4i a, vec3i b);

vec2 diff_vec2(vec2 a, vec2 b);
vec2 diff_vec2_vec3(vec2 a, vec3 b);
vec2 diff_vec2_vec4(vec2 a, vec4 b);
vec2i diff_vec2i(vec2i a, vec2i b);
vec2i diff_vec2i_vec3i(vec2i a, vec3i b);
vec2i diff_vec2i_vec4i(vec2i a, vec4i b);

vec3 diff_vec3(vec3 a, vec3 b);
vec3 diff_vec3_vec2(vec3 a, vec2 b);
vec3 diff_vec3_vec4(vec3 a, vec4 b);
vec3i diff_vec3i(vec3i a, vec3i b);
vec3i diff_vec3i_vec2i(vec3i a, vec2i b);
vec3i diff_vec3i_vec4i(vec3i a, vec4i b);

vec4 diff_vec4(vec4 a, vec4 b);
vec4 diff_vec4_vec2(vec4 a, vec2 b);
vec4 diff_vec4_vec3(vec4 a, vec3 b);
vec4i diff_vec4i(vec4i a, vec4i b);
vec4i diff_vec4i_vec2i(vec4i a, vec2i b);
vec4i diff_vec4i_vec3i(vec4i a, vec3i b);

vec2 vec3_to_vec2(vec3 a);
vec2 vec3i_to_vec2(vec3i a);
vec2i vec3_to_vec2i(vec3 a);
vec2 vec4_to_vec2(vec4 a);
vec2 vec4i_to_vec2(vec4i a);
vec2i vec4_to_vec2i(vec4 a);

vec3 vec2_to_vec3(vec2 a, float z);
vec3 vec2i_to_vec3(vec2i a, float z);
vec3i vec2_to_vec3i(vec2 a, int z);
vec3 vec4_to_vec3(vec4 a);
vec3 vec4i_to_vec3(vec4i a);
vec3i vec4_to_vec3i(vec4 a);

vec4 vec2_to_vec4(vec2 a, float z, float w);
vec4 vec2i_to_vec4(vec2i a, float z, float w);
vec4i vec2_to_vec4i(vec2 a, int z, int w);
vec4 vec3_to_vec4(vec3 a, float w);
vec4 vec3i_to_vec4(vec3i a, float w);
vec4i vec3_to_vec4i(vec3 a, int w);

void free_matrix(matrix *m);

void free_face(face *f);
void free_faces(faces *fs);

void free_vertices(vertices *vs);

#endif
