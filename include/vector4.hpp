#ifndef __VECTOR4_HPP__
#define __VECTOR4_HPP__

#include "vector3.hpp"

class vector4 : public vector3 {
public:
  double w;

  vector4();
  vector4(double _value);
  vector4(const vector3 &v, double _w);
  vector4(const vector2 &v, double _z, double _w);
  vector4(double _x, double _y, double _z, double _w);

  vector4 normalized() const;
  void normalize();

  vector4 operator-() const;
  vector4 operator+(const vector4 &v) const;
  vector4 &operator+=(const vector4 &v);
  vector4 operator*(const vector4 &v) const;
  vector4 &operator*=(const vector4 &v);
  vector4 operator-(const vector4 &v) const;
  vector4 &operator-=(const vector4 &v);
  vector4 operator/(const vector4 &v) const;
  vector4 &operator/=(const vector4 &v);
  friend std::ostream &operator<<(std::ostream &os, const vector4 &v);
};

#endif
