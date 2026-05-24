#include "vector4.hpp"
#include "matrix.hpp"
#include <cmath>

vector4::vector4() : vector3(), w() {}
vector4::vector4(double _value) : vector3(_value), w(_value) {}
vector4::vector4(const vector3 &v, double _w) : vector3(v), w(_w) {}
vector4::vector4(const vector2 &v, double _z, double _w)
    : vector3(v, _z), w(_w) {}
vector4::vector4(double _x, double _y, double _z, double _w)
    : vector3(_x, _y, _z), w(_w) {}

vector4 vector4::normalized() const {
  return *this / std::sqrt(x * x + y * y + z * z + w * w);
}
void vector4::normalize() { *this = normalized(); }

vector4 vector4::operator-() const { return vector4(-x, -y, -z, -w); }
vector4 vector4::operator+(const vector4 &v) const {
  return vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}
vector4 &vector4::operator+=(const vector4 &v) { return *this = *this + v; }
vector4 vector4::operator-(const vector4 &v) const {
  return vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}
vector4 &vector4::operator-=(const vector4 &v) { return *this = *this - v; }
vector4 vector4::operator*(const vector4 &v) const {
  return vector4(x * v.x, y * v.y, z * v.z, w * v.w);
}
vector4 &vector4::operator*=(const vector4 &v) { return *this = *this * v; }
vector4 vector4::operator/(const vector4 &v) const {
  return vector4(x / v.x, y / v.y, z / v.z, w / v.w);
}
vector4 &vector4::operator/=(const vector4 &v) { return *this = *this / v; }
std::ostream &operator<<(std::ostream &os, const vector4 &v) {
  os << "x: " << v.x << " y: " << v.y << " z: " << v.z << " w: " << v.w;
  return os;
}
