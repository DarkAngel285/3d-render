#include "vector2.hpp"
#include "matrix.hpp"
#include <cmath>

vector2::vector2() : x(), y() {}
vector2::vector2(double _value) : x(_value), y(_value) {}
vector2::vector2(double _x, double _y) : x(_x), y(_y) {}

vector2 vector2::normalized() const { return *this / std::sqrt(x * x + y * y); }
void vector2::normalize() { *this = normalized(); }

vector2 vector2::operator-() const { return vector2(-x, -y); }
vector2 vector2::operator+(const vector2 &v) const {
  return vector2(x + v.x, y + v.y);
}
vector2 &vector2::operator+=(const vector2 &v) { return *this = *this + v; }
vector2 vector2::operator-(const vector2 &v) const {
  return vector2(x - v.x, y - v.y);
}
vector2 &vector2::operator-=(const vector2 &v) { return *this = *this - v; }
vector2 vector2::operator*(const vector2 &v) const {
  return vector2(x * v.x, y * v.y);
}
vector2 &vector2::operator*=(const vector2 &v) { return *this = *this * v; }
vector2 vector2::operator/(const vector2 &v) const {
  return vector2(x / v.x, y / v.y);
}
vector2 &vector2::operator/=(const vector2 &v) { return *this = *this / v; }
std::ostream &operator<<(std::ostream &os, const vector2 &v) {
  os << "x: " << v.x << " y: " << v.y;
  return os;
}
