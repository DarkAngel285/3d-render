#include "3d_structs.h"

/* --- Convertation methods --- */

/* -- Vector2 -- */
vec2i *vec2_to_vec2i(vec2 *a) {
  vec2i *result = new_vec2i(a->x, a->y);
  return result;
}
vec3 *vec2_to_vec3(vec2 *a, float z) {
  vec3 *result = new_vec3(a->x, a->y, z);
  return result;
}
vec3i *vec2_to_vec3i(vec2 *a, int z) {
  vec3i *result = new_vec3i(a->x, a->y, z);
  return result;
}
vec4 *vec2_to_vec4(vec2 *a, float z, float w) {
  vec4 *result = new_vec4(a->x, a->y, z, w);
  return result;
}
vec4i *vec2_to_vec4i(vec2 *a, int z, int w) {
  vec4i *result = new_vec4i(a->x, a->y, z, w);
  return result;
}

/* -- Vector2 int -- */
vec2 *vec2i_to_vec2(vec2i *a) {
  vec2 *result = new_vec2(a->x, a->y);
  return result;
}
vec3 *vec2i_to_vec3(vec2i *a, float z) {
  vec3 *result = new_vec3(a->x, a->y, z);
  return result;
}
vec3i *vec2i_to_vec3i(vec2i *a, int z) {
  vec3i *result = new_vec3i(a->x, a->y, z);
  return result;
}
vec4 *vec2i_to_vec4(vec2i *a, float z, float w) {
  vec4 *result = new_vec4(a->x, a->y, z, w);
  return result;
}
vec4i *vec2i_to_vec4i(vec2i *a, int z, int w) {
  vec4i *result = new_vec4i(a->x, a->y, z, w);
  return result;
}

/* -- Vector3 -- */
vec3i *vec3_to_vec3i(vec3 *a) {
  vec3i *result = new_vec3i(a->x, a->y, a->z);
  return result;
}
vec2 *vec3_to_vec2(vec3 *a) {
  vec2 *result = new_vec2(a->x, a->y);
  return result;
}
vec2i *vec3_to_vec2i(vec3 *a) {
  vec2i *result = new_vec2i(a->x, a->y);
  return result;
}
vec4 *vec3_to_vec4(vec3 *a, float w) {
  vec4 *result = new_vec4(a->x, a->y, a->z, w);
  return result;
}
vec4i *vec3_to_vec4i(vec3 *a, int w) {
  vec4i *result = new_vec4i(a->x, a->y, a->z, w);
  return result;
}

/* -- Vector3 int -- */
vec3 *vec3i_to_vec3(vec3i *a) {
  vec3 *result = new_vec3(a->x, a->y, a->z);
  return result;
}
vec2 *vec3i_to_vec2(vec3i *a) {
  vec2 *result = new_vec2(a->x, a->y);
  return result;
}
vec2i *vec3i_to_vec2i(vec3i *a) {
  vec2i *result = new_vec2i(a->x, a->y);
  return result;
}
vec4 *vec3i_to_vec4(vec3i *a, float w) {
  vec4 *result = new_vec4(a->x, a->y, a->z, w);
  return result;
}
vec4i *vec3i_to_vec4i(vec3i *a, int w) {
  vec4i *result = new_vec4i(a->x, a->y, a->z, w);
  return result;
}

/* -- Vector4 -- */
vec4i *vec4_to_vec4i(vec4 *a) {
  vec4i *result = new_vec4i(a->x, a->y, a->z, a->w);
  return result;
}
vec2 *vec4_to_vec2(vec4 *a) {
  vec2 *result = new_vec2(a->x, a->y);
  return result;
}
vec2i *vec4_to_vec2i(vec4 *a) {
  vec2i *result = new_vec2i(a->x, a->y);
  return result;
}
vec3 *vec4_to_vec3(vec4 *a) {
  vec3 *result = new_vec3(a->x, a->y, a->z);
  return result;
}
vec3i *vec4_to_vec3i(vec4 *a) {
  vec3i *result = new_vec3i(a->x, a->y, a->z);
  return result;
}

/* -- Vector4 int -- */
vec4 *vec4i_to_vec4(vec4i *a) {
  vec4 *result = new_vec4(a->x, a->y, a->z, a->w);
  return result;
}
vec2 *vec4i_to_vec2(vec4i *a) {
  vec2 *result = new_vec2(a->x, a->y);
  return result;
}
vec2i *vec4i_to_vec2i(vec4i *a) {
  vec2i *result = new_vec2i(a->x, a->y);
  return result;
}
vec3 *vec4i_to_vec3(vec4i *a) {
  vec3 *result = new_vec3(a->x, a->y, a->z);
  return result;
}
vec3i *vec4i_to_vec3i(vec4i *a) {
  vec3i *result = new_vec3i(a->x, a->y, a->z);
  return result;
}
