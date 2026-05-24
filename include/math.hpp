#ifndef __MATH_HPP__
#define __MATH_HPP__

#define PI 3.14159

class vector2;
class vector3;
class vector4;

namespace math {
double to_radian(const double &d);
vector2 to_radian(const vector2 &v);
vector3 to_radian(const vector3 &v);
vector4 to_radian(const vector4 &v);

vector2 cos(const vector2 &v);
vector3 cos(const vector3 &v);
vector4 cos(const vector4 &v);

vector2 sin(const vector2 &v);
vector3 sin(const vector3 &v);
vector4 sin(const vector4 &v);
} // namespace math

#endif
