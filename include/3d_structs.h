#ifndef __3D_STRUCTS_H__
#define __3D_STRUCTS_H__

#include <stdlib.h>

/* --- Structures --- */

/* -- Vector2 -- */
typedef struct {
  float x, y;
} vec2;

/* -- Vector2 int -- */
typedef struct {
  int x, y;
} vec2i;

/* -- Vector3 -- */
typedef struct {
  float x, y, z;
} vec3;

/* -- Vector3 int -- */
typedef struct {
  int x, y, z;
} vec3i;

/* -- Vector4 -- */
typedef struct {
  float x, y, z, w;
} vec4;

/* -- Vector4 int -- */
typedef struct {
  int x, y, z, w;
} vec4i;

/* - Vectors methods - */
vec2 *new_vec2(float x, float y);
vec2i *new_vec2i(int x, int y);
vec3 *new_vec3(float x, float y, float z);
vec3i *new_vec3i(int x, int y, int z);
vec4 *new_vec4(float x, float y, float z, float w);
vec4i *new_vec4i(int x, int y, int z, int w);

/* -- Matrix -- */
typedef struct {
  size_t rows, cols;
  float **data;
} matrix;

/* - Matrix methods - */
matrix *new_empty_matrix(size_t rows, size_t cols);
matrix *new_matrix(size_t rows, size_t cols, float data[rows][cols]);
void free_matrix(matrix *m);

/* -- Angle -- */
typedef struct {
  double x, y, z;
} angle;

/* - Angle methods - */
angle *new_angle(double x, double y, double z);

/* -- Vertices -- */
typedef struct {
  size_t size;
  vec3 **data;
} vertices;

/* - Vertices methods - */
vertices *new_vertices();
void free_vertices(vertices *vs);
void add_vertex(vertices *vs, vec3 *v);

/* -- Face -- */
typedef struct {
  size_t size;
  int *data;
} face;

/* - Face methods - */
face *new_face();
void free_face(face *f);
void add_to_face(face *f, int i);

/* -- Faces -- */
typedef struct {
  size_t size;
  face **data;
} faces;

/* - Faces methods - */
faces *new_faces();
void free_faces(faces *fs);
void add_face(faces *fs, face *f);

/* --- Multiplication methods --- */

/* -- Vector2 -- */
vec2 *mult_vec2(vec2 *a, vec2 *b);
vec2 *mult_vec2_vec2i(vec2 *a, vec2i *b);
vec2 *mult_vec2_vec3(vec2 *a, vec3 *b);
vec2 *mult_vec2_vec3i(vec2 *a, vec3i *b);
vec2 *mult_vec2_vec4(vec2 *a, vec4 *b);
vec2 *mult_vec2_vec4i(vec2 *a, vec4i *b);

/* -- Vector2 int -- */
vec2i *mult_vec2i(vec2i *a, vec2i *b);
vec2i *mult_vec2i_vec2(vec2i *a, vec2 *b);
vec2i *mult_vec2i_vec3i(vec2i *a, vec3i *b);
vec2i *mult_vec2i_vec3(vec2i *a, vec3 *b);
vec2i *mult_vec2i_vec4i(vec2i *a, vec4i *b);
vec2i *mult_vec2i_vec4(vec2i *a, vec4 *b);

/* -- Vector3 -- */
vec3 *mult_vec3(vec3 *a, vec3 *b);
vec3 *mult_vec3_vec3i(vec3 *a, vec3i *b);
vec3 *mult_vec3_vec2(vec3 *a, vec2 *b);
vec3 *mult_vec3_vec2i(vec3 *a, vec2i *b);
vec3 *mult_vec3_vec4(vec3 *a, vec4 *b);
vec3 *mult_vec3_vec4i(vec3 *a, vec4i *b);

/* -- Vector3 int -- */
vec3i *mult_vec3i(vec3i *a, vec3i *b);
vec3i *mult_vec3i_vec3(vec3i *a, vec3 *b);
vec3i *mult_vec3i_vec2i(vec3i *a, vec2i *b);
vec3i *mult_vec3i_vec2(vec3i *a, vec2 *b);
vec3i *mult_vec3i_vec4i(vec3i *a, vec4i *b);
vec3i *mult_vec3i_vec4(vec3i *a, vec4 *b);

/* -- Vector4 -- */
vec4 *mult_vec4(vec4 *a, vec4 *b);
vec4 *mult_vec4_vec4i(vec4 *a, vec4i *b);
vec4 *mult_vec4_vec2(vec4 *a, vec2 *b);
vec4 *mult_vec4_vec2i(vec4 *a, vec2i *b);
vec4 *mult_vec4_vec3(vec4 *a, vec3 *b);
vec4 *mult_vec4_vec3i(vec4 *a, vec3i *b);

/* -- Vector4 int -- */
vec4i *mult_vec4i(vec4i *a, vec4i *b);
vec4i *mult_vec4i_vec4(vec4i *a, vec4 *b);
vec4i *mult_vec4i_vec2i(vec4i *a, vec2i *b);
vec4i *mult_vec4i_vec2(vec4i *a, vec2 *b);
vec4i *mult_vec4i_vec3i(vec4i *a, vec3i *b);
vec4i *mult_vec4i_vec3(vec4i *a, vec3 *b);

/* -- Matrix -- */
matrix *mult_matrix(matrix *a, matrix *b);
vec2 *mult_matrix_vec2(matrix *a, vec2 *b);
vec2i *mult_matrix_vec2i(matrix *a, vec2i *b);
vec3 *mult_matrix_vec3(matrix *a, vec3 *b);
vec3i *mult_matrix_vec3i(matrix *a, vec3i *b);
vec4 *mult_matrix_vec4(matrix *a, vec4 *b);
vec4i *mult_matrix_vec4i(matrix *a, vec4i *b);

/* --- Division methods --- */

/* -- Vector2 -- */
vec2 *div_vec2(vec2 *a, vec2 *b);
vec2 *div_vec2_vec2i(vec2 *a, vec2i *b);
vec2 *div_vec2_vec3(vec2 *a, vec3 *b);
vec2 *div_vec2_vec3i(vec2 *a, vec3i *b);
vec2 *div_vec2_vec4(vec2 *a, vec4 *b);
vec2 *div_vec2_vec4i(vec2 *a, vec4i *b);

/* -- Vector2 int -- */
vec2i *div_vec2i(vec2i *a, vec2i *b);
vec2i *div_vec2i_vec2(vec2i *a, vec2 *b);
vec2i *div_vec2i_vec3(vec2i *a, vec3 *b);
vec2i *div_vec2i_vec3i(vec2i *a, vec3i *b);
vec2i *div_vec2i_vec4(vec2i *a, vec4 *b);
vec2i *div_vec2i_vec4i(vec2i *a, vec4i *b);

/* -- Vector3 -- */
vec3 *div_vec3(vec3 *a, vec3 *b);
vec3 *div_vec3_vec2(vec3 *a, vec2 *b);
vec3 *div_vec3_vec2i(vec3 *a, vec2i *b);
vec3 *div_vec3_vec3i(vec3 *a, vec3i *b);
vec3 *div_vec3_vec4(vec3 *a, vec4 *b);
vec3 *div_vec3_vec4i(vec3 *a, vec4i *b);

/* -- Vector3 int -- */
vec3i *div_vec3i(vec3i *a, vec3i *b);
vec3i *div_vec3i_vec2(vec3i *a, vec2 *b);
vec3i *div_vec3i_vec2i(vec3i *a, vec2i *b);
vec3i *div_vec3i_vec3(vec3i *a, vec3 *b);
vec3i *div_vec3i_vec4(vec3i *a, vec4 *b);
vec3i *div_vec3i_vec4i(vec3i *a, vec4i *b);

/* -- Vector4 -- */
vec4 *div_vec4(vec4 *a, vec4 *b);
vec4 *div_vec4_vec2(vec4 *a, vec2 *b);
vec4 *div_vec4_vec2i(vec4 *a, vec2i *b);
vec4 *div_vec4_vec3(vec4 *a, vec3 *b);
vec4 *div_vec4_vec3i(vec4 *a, vec3i *b);
vec4 *div_vec4_vec4i(vec4 *a, vec4i *b);

/* -- Vector4 int -- */
vec4i *div_vec4i(vec4i *a, vec4i *b);
vec4i *div_vec4i_vec2(vec4i *a, vec2 *b);
vec4i *div_vec4i_vec2i(vec4i *a, vec2i *b);
vec4i *div_vec4i_vec3(vec4i *a, vec3 *b);
vec4i *div_vec4i_vec3i(vec4i *a, vec3i *b);
vec4i *div_vec4i_vec4(vec4i *a, vec4 *b);

/* --- Addition methods --- */

/* -- Vector2 -- */
vec2 *sum_vec2(vec2 *a, vec2 *b);
vec2 *sum_vec2_vec2i(vec2 *a, vec2i *b);
vec2 *sum_vec2_vec3(vec2 *a, vec3 *b);
vec2 *sum_vec2_vec3i(vec2 *a, vec3i *b);
vec2 *sum_vec2_vec4(vec2 *a, vec4 *b);
vec2 *sum_vec2_vec4i(vec2 *a, vec4i *b);

/* -- Vector2 int -- */
vec2i *sum_vec2i(vec2i *a, vec2i *b);
vec2i *sum_vec2i_vec2(vec2i *a, vec2 *b);
vec2i *sum_vec2i_vec3i(vec2i *a, vec3i *b);
vec2i *sum_vec2i_vec3(vec2i *a, vec3 *b);
vec2i *sum_vec2i_vec4i(vec2i *a, vec4i *b);
vec2i *sum_vec2i_vec4(vec2i *a, vec4 *b);

/* -- Vector3 -- */
vec3 *sum_vec3(vec3 *a, vec3 *b);
vec3 *sum_vec3_vec3i(vec3 *a, vec3i *b);
vec3 *sum_vec3_vec2(vec3 *a, vec2 *b);
vec3 *sum_vec3_vec2i(vec3 *a, vec2i *b);
vec3 *sum_vec3_vec4(vec3 *a, vec4 *b);
vec3 *sum_vec3_vec4i(vec3 *a, vec4i *b);

/* -- Vector3 int -- */
vec3i *sum_vec3i(vec3i *a, vec3i *b);
vec3i *sum_vec3i_vec3(vec3i *a, vec3 *b);
vec3i *sum_vec3i_vec2i(vec3i *a, vec2i *b);
vec3i *sum_vec3i_vec2(vec3i *a, vec2 *b);
vec3i *sum_vec3i_vec4i(vec3i *a, vec4i *b);
vec3i *sum_vec3i_vec4(vec3i *a, vec4 *b);

/* -- Vector4 -- */
vec4 *sum_vec4(vec4 *a, vec4 *b);
vec4 *sum_vec4_vec4i(vec4 *a, vec4i *b);
vec4 *sum_vec4_vec2(vec4 *a, vec2 *b);
vec4 *sum_vec4_vec2i(vec4 *a, vec2i *b);
vec4 *sum_vec4_vec3(vec4 *a, vec3 *b);
vec4 *sum_vec4_vec3i(vec4 *a, vec3i *b);

/* -- Vector4 int -- */
vec4i *sum_vec4i(vec4i *a, vec4i *b);
vec4i *sum_vec4i_vec4(vec4i *a, vec4 *b);
vec4i *sum_vec4i_vec2i(vec4i *a, vec2i *b);
vec4i *sum_vec4i_vec2(vec4i *a, vec2 *b);
vec4i *sum_vec4i_vec3i(vec4i *a, vec3i *b);
vec4i *sum_vec4i_vec3(vec4i *a, vec3 *b);

/* --- Substraction methods --- */

/* -- Vector2 -- */
vec2 *diff_vec2(vec2 *a, vec2 *b);
vec2 *diff_vec2_vec2i(vec2 *a, vec2i *b);
vec2 *diff_vec2_vec3(vec2 *a, vec3 *b);
vec2 *diff_vec2_vec3i(vec2 *a, vec3i *b);
vec2 *diff_vec2_vec4(vec2 *a, vec4 *b);
vec2 *diff_vec2_vec4i(vec2 *a, vec4i *b);

/* -- Vector2 int -- */
vec2i *diff_vec2i(vec2i *a, vec2i *b);
vec2i *diff_vec2i_vec2(vec2i *a, vec2 *b);
vec2i *diff_vec2i_vec3i(vec2i *a, vec3i *b);
vec2i *diff_vec2i_vec3(vec2i *a, vec3 *b);
vec2i *diff_vec2i_vec4i(vec2i *a, vec4i *b);
vec2i *diff_vec2i_vec4(vec2i *a, vec4 *b);

/* -- Vector3 -- */
vec3 *diff_vec3(vec3 *a, vec3 *b);
vec3 *diff_vec3_vec3i(vec3 *a, vec3i *b);
vec3 *diff_vec3_vec2(vec3 *a, vec2 *b);
vec3 *diff_vec3_vec2i(vec3 *a, vec2i *b);
vec3 *diff_vec3_vec4(vec3 *a, vec4 *b);
vec3 *diff_vec3_vec4i(vec3 *a, vec4i *b);

/* -- Vector3 int -- */
vec3i *diff_vec3i(vec3i *a, vec3i *b);
vec3i *diff_vec3i_vec3(vec3i *a, vec3 *b);
vec3i *diff_vec3i_vec2i(vec3i *a, vec2i *b);
vec3i *diff_vec3i_vec2(vec3i *a, vec2 *b);
vec3i *diff_vec3i_vec4i(vec3i *a, vec4i *b);
vec3i *diff_vec3i_vec4(vec3i *a, vec4 *b);

/* -- Vector4 -- */
vec4 *diff_vec4(vec4 *a, vec4 *b);
vec4 *diff_vec4_vec4i(vec4 *a, vec4i *b);
vec4 *diff_vec4_vec2(vec4 *a, vec2 *b);
vec4 *diff_vec4_vec2i(vec4 *a, vec2i *b);
vec4 *diff_vec4_vec3(vec4 *a, vec3 *b);
vec4 *diff_vec4_vec3i(vec4 *a, vec3i *b);

/* -- Vector4 int -- */
vec4i *diff_vec4i(vec4i *a, vec4i *b);
vec4i *diff_vec4i_vec4(vec4i *a, vec4 *b);
vec4i *diff_vec4i_vec2i(vec4i *a, vec2i *b);
vec4i *diff_vec4i_vec2(vec4i *a, vec2 *b);
vec4i *diff_vec4i_vec3i(vec4i *a, vec3i *b);
vec4i *diff_vec4i_vec3(vec4i *a, vec3 *b);

/* --- Convertation methods --- */

/* -- Vector2 -- */
vec2i *vec2_to_vec2i(vec2 *a);
vec3 *vec2_to_vec3(vec2 *a, float z);
vec3i *vec2_to_vec3i(vec2 *a, int z);
vec4 *vec2_to_vec4(vec2 *a, float z, float w);
vec4i *vec2_to_vec4i(vec2 *a, int z, int w);

/* -- Vector2 int -- */
vec2 *vec2i_to_vec2(vec2i *a);
vec3 *vec2i_to_vec3(vec2i *a, float z);
vec3i *vec2i_to_vec3i(vec2i *a, int z);
vec4 *vec2i_to_vec4(vec2i *a, float z, float w);
vec4i *vec2i_to_vec4i(vec2i *a, int z, int w);

/* -- Vector3 -- */
vec3i *vec3_to_vec3i(vec3 *a);
vec2 *vec3_to_vec2(vec3 *a);
vec2i *vec3_to_vec2i(vec3 *a);
vec4 *vec3_to_vec4(vec3 *a, float w);
vec4i *vec3_to_vec4i(vec3 *a, int w);

/* -- Vector3 int -- */
vec3 *vec3i_to_vec3(vec3i *a);
vec2 *vec3i_to_vec2(vec3i *a);
vec2i *vec3i_to_vec2i(vec3i *a);
vec4 *vec3i_to_vec4(vec3i *a, float w);
vec4i *vec3i_to_vec4i(vec3i *a, int w);

/* -- Vector4 -- */
vec4i *vec4_to_vec4i(vec4 *a);
vec2 *vec4_to_vec2(vec4 *a);
vec2i *vec4_to_vec2i(vec4 *a);
vec3 *vec4_to_vec3(vec4 *a);
vec3i *vec4_to_vec3i(vec4 *a);

/* -- Vector4 int -- */
vec4 *vec4i_to_vec4(vec4i *a);
vec2 *vec4i_to_vec2(vec4i *a);
vec2i *vec4i_to_vec2i(vec4i *a);
vec3 *vec4i_to_vec3(vec4i *a);
vec3i *vec4i_to_vec3i(vec4i *a);

#endif
