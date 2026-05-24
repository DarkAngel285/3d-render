#include "matrix.hpp"
#include "buffer.hpp"
#include "math.hpp"
#include "vector4.hpp"
#include <cassert>
#include <cmath>

matrix::matrix() : rows(), cols(), data() {}
matrix::matrix(std::size_t _rows, std::size_t _cols)
    : rows(_rows), cols(_cols), data(rows, std::vector<double>(cols)) {}
matrix::matrix(std::size_t _rows, std::size_t _cols,
               std::vector<std::vector<double>> _data)
    : rows(_rows), cols(_cols), data(rows, std::vector<double>(cols)) {
  for (std::size_t i = 0; i < rows && i < _data.size(); i++)
    for (std::size_t j = 0; j < cols && j < _data[i].size(); j++)
      data[i][j] = _data[i][j];
}

std::vector<std::vector<double>>::iterator matrix::begin() {
  return data.begin();
}
std::vector<std::vector<double>>::iterator matrix::end() { return data.end(); }

std::vector<double> &matrix::operator[](const std::size_t &i) {
  return data[i];
}
const std::vector<double> &matrix::operator[](const std::size_t &i) const {
  return data[i];
}

matrix matrix::operator*(const matrix &m) const {
  assert(cols == m.rows);

  matrix result = matrix(rows, m.cols);

  for (std::size_t i = 0; i < result.rows; i++)
    for (std::size_t j = 0; j < result.cols; j++)
      for (std::size_t k = 0; k < cols; k++)
        result[i][j] += data[i][k] * m.data[k][j];

  return result;
}
matrix &matrix::operator*=(const matrix &m) { return *this = *this * m; }
vector2 matrix::operator*(const vector2 &m) const {
  matrix result = *this * matrix(2, 1, {{m.x}, {m.y}});
  return vector2(result[0][0], result[1][0]);
}
vector3 matrix::operator*(const vector3 &m) const {
  matrix result = *this * matrix(3, 1, {{m.x}, {m.y}, {m.z}});
  return vector3(result[0][0], result[1][0], result[2][0]);
}
vector4 matrix::operator*(const vector4 &m) const {
  matrix result = *this * matrix(4, 1, {{m.x}, {m.y}, {m.z}, {m.w}});
  return vector4(result[0][0], result[1][0], result[2][0], result[3][0]);
}

matrix matrices::translation(const vector3 &t) {
  return matrix(4, 4,
                {{1, 0, 0, t.x}, {0, 1, 0, t.y}, {0, 0, 1, t.z}, {0, 0, 0, 1}});
}
matrix matrices::x_rotation(const double &rx) {
  const double cos_rx = std::cos(rx), sin_rx = std::sin(rx);
  return matrix(4, 4,
                {{1, 0, 0, 0},
                 {0, cos_rx, -sin_rx, 0},
                 {0, sin_rx, cos_rx, 0},
                 {0, 0, 0, 1}});
}
matrix matrices::y_rotation(const double &ry) {
  const double cos_ry = std::cos(ry), sin_ry = std::sin(ry);
  return matrix(4, 4,
                {{cos_ry, 0, sin_ry, 0},
                 {0, 1, 0, 0},
                 {-sin_ry, 0, cos_ry, 0},
                 {0, 0, 0, 1}});
}
matrix matrices::z_rotation(const double &rz) {
  const double cos_rz = std::cos(rz), sin_rz = std::sin(rz);
  return matrix(4, 4,
                {{cos_rz, -sin_rz, 0, 0},
                 {sin_rz, cos_rz, 0, 0},
                 {0, 0, 1, 0},
                 {0, 0, 0, 1}});
}
matrix matrices::rotation(const vector3 &r) {
  const vector3 rad_r = math::to_radian(r);
  return matrices::z_rotation(rad_r.z) * matrices::y_rotation(rad_r.y) *
         matrices::x_rotation(rad_r.x);
}
matrix matrices::scale(const vector3 &s) {
  return matrix(4, 4,
                {{s.x, 0, 0, 0}, {0, s.y, 0, 0}, {0, 0, s.z, 0}, {0, 0, 0, 1}});
}
matrix matrices::model(const vector3 &position, const vector3 &rotation,
                       const vector3 &scale) {
  return matrices::translation(position) * matrices::rotation(rotation) *
         matrices::scale(scale);
}
matrix matrices::view(const vector3 &position, const vector3 &direction,
                      const vector3 &up) {
  vector3 f = direction.normalized(), r = cross(up, f).normalized(),
          u = cross(f, r).normalized();
  return matrix(4, 4,
                {{r.x, r.y, r.z, -dot(r, position)},
                 {u.x, u.y, u.z, -dot(u, position)},
                 {f.x, f.y, f.z, -dot(f, position)},
                 {0, 0, 0, 1.0}});
}
matrix matrices::perspective_projection(const double &fov, const double &near_z,
                                        const double &far_z,
                                        const double &screen_width,
                                        const double &screen_height) {
  const double aspect = (screen_width / screen_height) * SYMBOL_ASPECT,
               ctg_half_fov = 1.0 / std::tan(math::to_radian(fov / 2.0));
  return matrix(4, 4,
                {{ctg_half_fov / aspect, 0, 0, 0},
                 {0, ctg_half_fov, 0, 0},
                 {0, 0, (far_z + near_z) / (far_z - near_z),
                  (-2.0 * far_z * near_z) / (far_z - near_z)},
                 {0, 0, 1, 0}});
}
