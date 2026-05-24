#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

#include <iostream>

class vector2 {
public:
  double x, y;

  vector2();
  vector2(double _value);
  vector2(double _x, double _y);

  vector2 normalized() const;
  void normalize();

  vector2 operator-() const;
  vector2 operator+(const vector2 &v) const;
  vector2 &operator+=(const vector2 &v);
  vector2 operator-(const vector2 &v) const;
  vector2 &operator-=(const vector2 &v);
  vector2 operator*(const vector2 &v) const;
  vector2 &operator*=(const vector2 &v);
  vector2 operator/(const vector2 &v) const;
  vector2 &operator/=(const vector2 &v);
  friend std::ostream &operator<<(std::ostream &os, const vector2 &v);
};

#endif
