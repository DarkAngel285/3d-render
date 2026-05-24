#pragma once
#ifndef __QUATERNION_HPP__
#define __QUATERNION_HPP__

class vector3;
class vector4;

class quaternion {
public:
  double w, x, y, z;

  quaternion();
  quaternion(double _value);
  quaternion(double _axis, const vector3 &v);
  quaternion(double _w, double _x, double _y, double _z);

  quaternion operator+(const quaternion &q);
  quaternion &operator+=(const quaternion &q);
  quaternion operator-(const quaternion &q);
  quaternion &operator-=(const quaternion &q);
  quaternion operator*(const quaternion &q);
  quaternion &operator*=(const quaternion &q);
  quaternion operator/(const quaternion &q);
  quaternion &operator/=(const quaternion &q);
};

#endif
