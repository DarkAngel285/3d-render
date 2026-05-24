#include "math.hpp"
#include "vector4.hpp"
#include <cmath>

double math::to_radian(const double &d) { return d / 180 * PI; }
vector2 math::to_radian(const vector2 &v) {
  return vector2(to_radian(v.x), to_radian(v.y));
}
vector3 math::to_radian(const vector3 &v) {
  return vector3(to_radian(v.x), to_radian(v.y), to_radian(v.z));
}
vector4 math::to_radian(const vector4 &v) {
  return vector4(to_radian(v.x), to_radian(v.y), to_radian(v.z),
                 to_radian(v.w));
}

vector2 math::cos(const vector2 &v) {
  return vector2(std::cos(v.x), std::cos(v.y));
}
vector3 math::cos(const vector3 &v) {
  return vector3(std::cos(v.x), std::cos(v.y), std::cos(v.z));
}
vector4 math::cos(const vector4 &v) {
  return vector4(std::cos(v.x), std::cos(v.y), std::cos(v.z), std::cos(v.w));
}

vector2 math::sin(const vector2 &v) {
  return vector2(std::sin(v.x), std::sin(v.y));
}
vector3 math::sin(const vector3 &v) {
  return vector3(std::sin(v.x), std::sin(v.y), std::sin(v.z));
}
vector4 math::sin(const vector4 &v) {
  return vector4(std::sin(v.x), std::sin(v.y), std::sin(v.z), std::sin(v.w));
}
