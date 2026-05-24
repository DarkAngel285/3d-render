#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <vector>

class vector2;
class vector3;
class vector4;

class matrix {
public:
  std::size_t rows, cols;
  std::vector<std::vector<double>> data;

  matrix();
  matrix(std::size_t _rows, std::size_t _cols);
  matrix(std::size_t _rows, std::size_t _cols,
         std::vector<std::vector<double>> _data);

  std::vector<std::vector<double>>::iterator begin();
  std::vector<std::vector<double>>::iterator end();

  std::vector<double> &operator[](const std::size_t &i);
  const std::vector<double> &operator[](const std::size_t &i) const;

  matrix operator*(const matrix &v) const;
  matrix &operator*=(const matrix &v);
  vector2 operator*(const vector2 &v) const;
  vector3 operator*(const vector3 &v) const;
  vector4 operator*(const vector4 &v) const;
};

namespace matrices {
matrix model(const vector3 &position, const vector3 &rotation,
             const vector3 &scale);
matrix translation(const vector3 &t);
matrix x_rotation(const double &rx);
matrix y_rotation(const double &ry);
matrix z_rotation(const double &rz);
matrix rotation(const vector3 &r);
matrix scale(const vector3 &s);
matrix view(const vector3 &position, const vector3 &direction,
            const vector3 &up);
matrix perspective_projection(const double &fov, const double &near_z,
                              const double &far_z, const double &screen_width,
                              const double &screen_height);
} // namespace matrices

#endif
