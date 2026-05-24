#include "quaternion.hpp"
#include "vector3.hpp"
#include <cmath>

quaternion::quaternion() : w(), x(), y(), z() {}
quaternion::quaternion(double _value)
    : w(_value), x(_value), y(_value), z(_value) {}
quaternion::quaternion(double _axis, const vector3 &v)
    : w(cos(_axis / 2)), x(sin(_axis / 2) * v.x), y(sin(_axis / 2) * v.y),
      z(sin(_axis / 2) * v.z) {}
quaternion::quaternion(double _w, double _x, double _y, double _z)
    : w(_w), x(_x), y(_y), z(_z) {}

quaternion quaternion::operator+(const quaternion &q) {
  return quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}
quaternion &quaternion::operator+=(const quaternion &q) {
  return *this = *this + q;
}
quaternion quaternion::operator-(const quaternion &q) {
  return quaternion(w - q.w, x - q.x, y - q.y, z - q.z);
}
quaternion &quaternion::operator-=(const quaternion &q) {
  return *this = *this - q;
}
quaternion quaternion::operator*(const quaternion &q) {
  return quaternion(w * q.w - x * q.x - y * q.y - z * q.z,
                    w * q.x + x * q.w + y * q.z - z * q.y,
                    w * q.y - x * q.z + y * q.w + z * q.x,
                    w * q.z + x * q.y - y * q.x + z * q.w);
}
quaternion &quaternion::operator*=(const quaternion &q) {
  return *this = *this * q;
}
quaternion quaternion::operator/(const quaternion &q) {
  return quaternion(w / q.w - x / q.x - y / q.y - z / q.z,
                    w / q.x + x / q.w + y / q.z - z / q.y,
                    w / q.y - x / q.z + y / q.w + z / q.x,
                    w / q.z + x / q.y - y / q.x + z / q.w);
}
quaternion &quaternion::operator/=(const quaternion &q) {
  return *this = *this * q;
}
