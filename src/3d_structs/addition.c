#include "3d_structs.h"

/* --- Addition methods --- */

/* -- Vector2 -- */
vec2 *sum_vec2(vec2 *a, vec2 *b) {
  vec2 *result = new_vec2(a->x + b->x, a->y + b->y);
  return result;
};
vec2 *sum_vec2_vec2i(vec2 *a, vec2i *b) {
  vec2 *result = new_vec2(a->x + b->x, a->y + b->y);
  return result;
}
vec2 *sum_vec2_vec3(vec2 *a, vec3 *b) {
  vec2 *result = new_vec2(a->x + b->x, a->y + b->y);
  return result;
}
vec2 *sum_vec2_vec3i(vec2 *a, vec3i *b) {
  vec2 *result = new_vec2(a->x + b->x, a->y + b->y);
  return result;
}
vec2 *sum_vec2_vec4(vec2 *a, vec4 *b) {
  vec2 *result = new_vec2(a->x + b->x, a->y + b->y);
  return result;
}
vec2 *sum_vec2_vec4i(vec2 *a, vec4i *b) {
  vec2 *result = new_vec2(a->x + b->x, a->y + b->y);
  return result;
}

/* -- Vector2 int -- */
vec2i *sum_vec2i(vec2i *a, vec2i *b) {
  vec2i *result = new_vec2i(a->x + b->x, a->y + b->y);
  return result;
}
vec2i *sum_vec2i_vec2(vec2i *a, vec2 *b) {
  vec2i *result = new_vec2i(a->x + b->x, a->y + b->y);
  return result;
}
vec2i *sum_vec2i_vec3i(vec2i *a, vec3i *b) {
  vec2i *result = new_vec2i(a->x + b->x, a->y + b->y);
  return result;
}
vec2i *sum_vec2i_vec3(vec2i *a, vec3 *b) {
  vec2i *result = new_vec2i(a->x + b->x, a->y + b->y);
  return result;
}
vec2i *sum_vec2i_vec4i(vec2i *a, vec4i *b) {
  vec2i *result = new_vec2i(a->x + b->x, a->y + b->y);
  return result;
}
vec2i *sum_vec2i_vec4(vec2i *a, vec4 *b) {
  vec2i *result = new_vec2i(a->x + b->x, a->y + b->y);
  return result;
}

/* -- Vector3 -- */
vec3 *sum_vec3(vec3 *a, vec3 *b) {
  vec3 *result = new_vec3(a->x + b->x, a->y + b->y, a->z + b->z);
  return result;
}
vec3 *sum_vec3_vec3i(vec3 *a, vec3i *b) {
  vec3 *result = new_vec3(a->x + b->x, a->y + b->y, a->z + b->z);
  return result;
}
vec3 *sum_vec3_vec2(vec3 *a, vec2 *b) {
  vec3 *result = new_vec3(a->x + b->x, a->y + b->y, a->z);
  return result;
}
vec3 *sum_vec3_vec2i(vec3 *a, vec2i *b) {
  vec3 *result = new_vec3(a->x + b->x, a->y + b->y, a->z);
  return result;
}
vec3 *sum_vec3_vec4(vec3 *a, vec4 *b) {
  vec3 *result = new_vec3(a->x + b->x, a->y + b->y, a->z + b->z);
  return result;
}
vec3 *sum_vec3_vec4i(vec3 *a, vec4i *b) {
  vec3 *result = new_vec3(a->x + b->x, a->y + b->y, a->z + b->z);
  return result;
}

/* -- Vector3 int -- */
vec3i *sum_vec3i(vec3i *a, vec3i *b) {
  vec3i *result = new_vec3i(a->x + b->x, a->y + b->y, a->z + b->z);
  return result;
}
vec3i *sum_vec3i_vec3(vec3i *a, vec3 *b) {
  vec3i *result = new_vec3i(a->x + b->x, a->y + b->y, a->z + b->z);
  return result;
}
vec3i *sum_vec3i_vec2i(vec3i *a, vec2i *b) {
  vec3i *result = new_vec3i(a->x + b->x, a->y + b->y, a->z);
  return result;
}
vec3i *sum_vec3i_vec2(vec3i *a, vec2 *b) {
  vec3i *result = new_vec3i(a->x + b->x, a->y + b->y, a->z);
  return result;
}
vec3i *sum_vec3i_vec4i(vec3i *a, vec4i *b) {
  vec3i *result = new_vec3i(a->x + b->x, a->y + b->y, a->z + b->z);
  return result;
}
vec3i *sum_vec3i_vec4(vec3i *a, vec4 *b) {
  vec3i *result = new_vec3i(a->x + b->x, a->y + b->y, a->z + b->z);
  return result;
}

/* -- Vector4 -- */
vec4 *sum_vec4(vec4 *a, vec4 *b) {
  vec4 *result = new_vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w);
  return result;
}
vec4 *sum_vec4_vec4i(vec4 *a, vec4i *b) {
  vec4 *result = new_vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w);
  return result;
}
vec4 *sum_vec4_vec2(vec4 *a, vec2 *b) {
  vec4 *result = new_vec4(a->x + b->x, a->y + b->y, a->z, a->w);
  return result;
}
vec4 *sum_vec4_vec2i(vec4 *a, vec2i *b) {
  vec4 *result = new_vec4(a->x + b->x, a->y + b->y, a->z, a->w);
  return result;
}
vec4 *sum_vec4_vec3(vec4 *a, vec3 *b) {
  vec4 *result = new_vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
  return result;
}
vec4 *sum_vec4_vec3i(vec4 *a, vec3i *b) {
  vec4 *result = new_vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
  return result;
}

/* -- Vector4 int -- */
vec4i *sum_vec4i(vec4i *a, vec4i *b) {
  vec4i *result = new_vec4i(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w);
  return result;
}
vec4i *sum_vec4i_vec4(vec4i *a, vec4 *b) {
  vec4i *result = new_vec4i(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w);
  return result;
}
vec4i *sum_vec4i_vec2i(vec4i *a, vec2i *b) {
  vec4i *result = new_vec4i(a->x + b->x, a->y + b->y, a->z, a->w);
  return result;
}
vec4i *sum_vec4i_vec2(vec4i *a, vec2 *b) {
  vec4i *result = new_vec4i(a->x + b->x, a->y + b->y, a->z, a->w);
  return result;
}
vec4i *sum_vec4i_vec3i(vec4i *a, vec3i *b) {
  vec4i *result = new_vec4i(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
  return result;
}
vec4i *sum_vec4i_vec3(vec4i *a, vec3 *b) {
  vec4i *result = new_vec4i(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
  return result;
}
