#ifndef __VECTOR3_HPP__
#define __VECTOR3_HPP__

#include "vector2.hpp"

class vector3 : public vector2 {
public:
  double z;

  vector3();
  vector3(double _value);
  vector3(const vector2 &v, double _z);
  vector3(double _x, double _y, double _z);

  vector3 normalized() const;
  void normalize();

  friend vector3 cross(const vector3 &a, const vector3 &b);
  friend double dot(const vector3 &a, const vector3 &b);

  vector3 operator-() const;
  vector3 operator+(const vector3 &v) const;
  vector3 &operator+=(const vector3 &v);
  vector3 operator-(const vector3 &v) const;
  vector3 &operator-=(const vector3 &v);
  vector3 operator*(const vector3 &v) const;
  vector3 &operator*=(const vector3 &v);
  vector3 operator/(const vector3 &v) const;
  vector3 &operator/=(const vector3 &v);
  friend std::ostream &operator<<(std::ostream &os, const vector3 &v);
};

#endif
