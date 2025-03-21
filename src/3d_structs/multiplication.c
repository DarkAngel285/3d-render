#include "3d_structs.h"

/* --- Multiplication methods --- */

/* -- Vector2 -- */
vec2 *mult_vec2(vec2 *a, vec2 *b) {
  vec2 *result = new_vec2(a->x * b->x, a->y * b->y);
  return result;
}
vec2 *mult_vec2_vec2i(vec2 *a, vec2i *b) {
  vec2 *result = new_vec2(a->x * b->x, a->y * b->y);
  return result;
}
vec2 *mult_vec2_vec3(vec2 *a, vec3 *b) {
  vec2 *result = new_vec2(a->x * b->x, a->y * b->y);
  return result;
}
vec2 *mult_vec2_vec3i(vec2 *a, vec3i *b) {
  vec2 *result = new_vec2(a->x * b->x, a->y * b->y);
  return result;
}
vec2 *mult_vec2_vec4(vec2 *a, vec4 *b) {
  vec2 *result = new_vec2(a->x * b->x, a->y * b->y);
  return result;
}
vec2 *mult_vec2_vec4i(vec2 *a, vec4i *b) {
  vec2 *result = new_vec2(a->x * b->x, a->y * b->y);
  return result;
}

/* -- Vector2 int -- */
vec2i *mult_vec2i(vec2i *a, vec2i *b) {
  vec2i *result = new_vec2i(a->x * b->x, a->y * b->y);
  return result;
};
vec2i *mult_vec2i_vec2(vec2i *a, vec2 *b) {
  vec2i *result = new_vec2i(a->x * b->x, a->y * b->y);
  return result;
};
vec2i *mult_vec2i_vec3i(vec2i *a, vec3i *b) {
  vec2i *result = new_vec2i(a->x * b->x, a->y * b->y);
  return result;
};
vec2i *mult_vec2i_vec3(vec2i *a, vec3 *b) {
  vec2i *result = new_vec2i(a->x * b->x, a->y * b->y);
  return result;
};
vec2i *mult_vec2i_vec4i(vec2i *a, vec4i *b) {
  vec2i *result = new_vec2i(a->x * b->x, a->y * b->y);
  return result;
};
vec2i *mult_vec2i_vec4(vec2i *a, vec4 *b) {
  vec2i *result = new_vec2i(a->x * b->x, a->y * b->y);
  return result;
};

/* -- Vector3 -- */
vec3 *mult_vec3(vec3 *a, vec3 *b) {
  vec3 *result = new_vec3(a->x * b->x, a->y * b->y, a->z * b->z);
  return result;
};
vec3 *mult_vec3_vec3i(vec3 *a, vec3i *b) {
  vec3 *result = new_vec3(a->x * b->x, a->y * b->y, a->z * b->z);
  return result;
};
vec3 *mult_vec3_vec2(vec3 *a, vec2 *b) {
  vec3 *result = new_vec3(a->x * b->x, a->y * b->y, a->z);
  return result;
};
vec3 *mult_vec3_vec2i(vec3 *a, vec2i *b) {
  vec3 *result = new_vec3(a->x * b->x, a->y * b->y, a->z);
  return result;
};
vec3 *mult_vec3_vec4(vec3 *a, vec4 *b) {
  vec3 *result = new_vec3(a->x * b->x, a->y * b->y, a->z * b->z);
  return result;
};
vec3 *mult_vec3_vec4i(vec3 *a, vec4i *b) {
  vec3 *result = new_vec3(a->x * b->x, a->y * b->y, a->z * b->z);
  return result;
};

/* -- Vector3 int -- */
vec3i *mult_vec3i(vec3i *a, vec3i *b) {
  vec3i *result = new_vec3i(a->x * b->x, a->y * b->y, a->z * b->z);
  return result;
};
vec3i *mult_vec3i_vec3(vec3i *a, vec3 *b) {
  vec3i *result = new_vec3i(a->x * b->x, a->y * b->y, a->z * b->z);
  return result;
};
vec3i *mult_vec3i_vec2i(vec3i *a, vec2i *b) {
  vec3i *result = new_vec3i(a->x * b->x, a->y * b->y, a->z);
  return result;
};
vec3i *mult_vec3i_vec2(vec3i *a, vec2 *b) {
  vec3i *result = new_vec3i(a->x * b->x, a->y * b->y, a->z);
  return result;
};
vec3i *mult_vec3i_vec4i(vec3i *a, vec4i *b) {
  vec3i *result = new_vec3i(a->x * b->x, a->y * b->y, a->z * b->z);
  return result;
};
vec3i *mult_vec3i_vec4(vec3i *a, vec4 *b) {
  vec3i *result = new_vec3i(a->x * b->x, a->y * b->y, a->z * b->z);
  return result;
};

/* -- Vector4 -- */
vec4 *mult_vec4(vec4 *a, vec4 *b) {
  vec4 *result = new_vec4(a->x * b->x, a->y * b->y, a->z * b->z, a->w * b->w);
  return result;
}
vec4 *mult_vec4_vec4i(vec4 *a, vec4i *b) {
  vec4 *result = new_vec4(a->x * b->x, a->y * b->y, a->z * b->z, a->w * b->w);
  return result;
}
vec4 *mult_vec4_vec2(vec4 *a, vec2 *b) {
  vec4 *result = new_vec4(a->x * b->x, a->y * b->y, a->z, a->w);
  return result;
}
vec4 *mult_vec4_vec2i(vec4 *a, vec2i *b) {
  vec4 *result = new_vec4(a->x * b->x, a->y * b->y, a->z, a->w);
  return result;
}
vec4 *mult_vec4_vec3(vec4 *a, vec3 *b) {
  vec4 *result = new_vec4(a->x * b->x, a->y * b->y, a->z * b->z, a->w);
  return result;
}
vec4 *mult_vec4_vec3i(vec4 *a, vec3i *b) {
  vec4 *result = new_vec4(a->x * b->x, a->y * b->y, a->z * b->z, a->w);
  return result;
}

/* -- Vector4 int -- */
vec4i *mult_vec4i(vec4i *a, vec4i *b) {
  vec4i *result = new_vec4i(a->x * b->x, a->y * b->y, a->z * b->z, a->w * b->w);
  return result;
}
vec4i *mult_vec4i_vec4(vec4i *a, vec4 *b) {
  vec4i *result = new_vec4i(a->x * b->x, a->y * b->y, a->z * b->z, a->w * b->w);
  return result;
}
vec4i *mult_vec4i_vec2i(vec4i *a, vec2i *b) {
  vec4i *result = new_vec4i(a->x * b->x, a->y * b->y, a->z, a->w);
  return result;
}
vec4i *mult_vec4i_vec2(vec4i *a, vec2 *b) {
  vec4i *result = new_vec4i(a->x * b->x, a->y * b->y, a->z, a->w);
  return result;
}
vec4i *mult_vec4i_vec3i(vec4i *a, vec3i *b) {
  vec4i *result = new_vec4i(a->x * b->x, a->y * b->y, a->z * b->z, a->w);
  return result;
}
vec4i *mult_vec4i_vec3(vec4i *a, vec3 *b) {
  vec4i *result = new_vec4i(a->x * b->x, a->y * b->y, a->z * b->z, a->w);
  return result;
}

/* -- Matrix -- */
matrix *mult_matrix(matrix *a, matrix *b) {
  if (a->cols != b->rows)
    return NULL;
  matrix *result = new_empty_matrix(a->rows, b->cols);
  for (size_t i = 0; i < result->rows; ++i) {
    for (size_t j = 0; j < result->cols; ++j) {
      float sum = 0;
      for (size_t k = 0; k < a->cols; ++k) {
        sum += a->data[i][k] * b->data[k][j];
      }
      result->data[i][j] = sum;
    }
  }
  return result;
}
vec2 *mult_matrix_vec2(matrix *a, vec2 *b) {
  if (a->rows != a->cols || a->cols != 2)
    return NULL;
  vec2 *result = new_vec2(a->data[0][0] * b->x + a->data[0][1] * b->y,
                          a->data[1][0] * b->x + a->data[1][1] * b->y);
  return result;
}
vec2i *mult_matrix_vec2i(matrix *a, vec2i *b) {
  if (a->rows != a->cols || a->cols != 2)
    return NULL;
  vec2i *result = new_vec2i(a->data[0][0] * b->x + a->data[0][1] * b->y,
                            a->data[1][0] * b->x + a->data[1][1] * b->y);
  return result;
}
vec3 *mult_matrix_vec3(matrix *a, vec3 *b) {
  if (a->rows != a->cols || a->cols != 3)
    return NULL;
  vec3 *result = new_vec3(
      a->data[0][0] * b->x + a->data[0][1] * b->y + a->data[0][2] * b->z,
      a->data[1][0] * b->x + a->data[1][1] * b->y + a->data[1][2] * b->z,
      a->data[2][0] * b->x + a->data[2][1] * b->y + a->data[2][2] * b->z);
  return result;
}
vec3i *mult_matrix_vec3i(matrix *a, vec3i *b) {
  if (a->rows != a->cols || a->cols != 3)
    return NULL;
  vec3i *result = new_vec3i(
      a->data[0][0] * b->x + a->data[0][1] * b->y + a->data[0][2] * b->z,
      a->data[1][0] * b->x + a->data[1][1] * b->y + a->data[1][2] * b->z,
      a->data[2][0] * b->x + a->data[2][1] * b->y + a->data[2][2] * b->z);
  return result;
}
vec4 *mult_matrix_vec4(matrix *a, vec4 *b) {
  if (a->rows != a->cols || a->cols != 4)
    return NULL;
  vec4 *result = new_vec4(a->data[0][0] * b->x + a->data[0][1] * b->y +
                              a->data[0][2] * b->z + a->data[0][3] * b->w,
                          a->data[1][0] * b->x + a->data[1][1] * b->y +
                              a->data[1][2] * b->z + a->data[1][3] * b->w,
                          a->data[2][0] * b->x + a->data[2][1] * b->y +
                              a->data[2][2] * b->z + a->data[2][3] * b->w,
                          a->data[3][0] * b->x + a->data[3][1] * b->y +
                              a->data[3][2] * b->z + a->data[3][3] * b->w);
  return result;
}
vec4i *mult_matrix_vec4i(matrix *a, vec4i *b) {
  if (a->rows != a->cols || a->cols != 4)
    return NULL;
  vec4i *result = new_vec4i(a->data[0][0] * b->x + a->data[0][1] * b->y +
                                a->data[0][2] * b->z + a->data[0][3] * b->w,
                            a->data[1][0] * b->x + a->data[1][1] * b->y +
                                a->data[1][2] * b->z + a->data[1][3] * b->w,
                            a->data[2][0] * b->x + a->data[2][1] * b->y +
                                a->data[2][2] * b->z + a->data[2][3] * b->w,
                            a->data[3][0] * b->x + a->data[3][1] * b->y +
                                a->data[3][2] * b->z + a->data[3][3] * b->w);
  return result;
}
