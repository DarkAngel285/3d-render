#include "vector3.hpp"
#include "matrix.hpp"
#include <cmath>

vector3::vector3() : vector2(), z(0) {}
vector3::vector3(double _value) : vector2(_value), z(_value) {}
vector3::vector3(const vector2 &v, double _z) : vector2(v), z(_z) {}
vector3::vector3(double _x, double _y, double _z) : vector2(_x, _y), z(_z) {}

vector3 vector3::normalized() const {
  return *this / std::sqrt(x * x + y * y + z * z);
}
void vector3::normalize() { *this = normalized(); }

vector3 cross(const vector3 &a, const vector3 &b) {
  return vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                 a.x * b.y - a.y * b.x);
}
double dot(const vector3 &a, const vector3 &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector3 vector3::operator-() const { return vector3(-x, -y, -z); }
vector3 vector3::operator+(const vector3 &v) const {
  return vector3(x + v.x, y + v.y, z + v.z);
}
vector3 &vector3::operator+=(const vector3 &v) { return *this = *this + v; }
vector3 vector3::operator-(const vector3 &v) const {
  return vector3(x - v.x, y - v.y, z - v.z);
}
vector3 &vector3::operator-=(const vector3 &v) { return *this = *this - v; }
vector3 vector3::operator*(const vector3 &v) const {
  return vector3(x * v.x, y * v.y, z * v.z);
}
vector3 &vector3::operator*=(const vector3 &v) { return *this = *this * v; }
vector3 vector3::operator/(const vector3 &v) const {
  return vector3(x / v.x, y / v.y, z / v.z);
}
vector3 &vector3::operator/=(const vector3 &v) { return *this = *this / v; }
std::ostream &operator<<(std::ostream &os, const vector3 &v) {
  os << "x: " << v.x << " y: " << v.y << " z:" << v.z;
  return os;
}
