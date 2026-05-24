#include "camera.hpp"

camera::camera() : position(), direction(), up(), fov(), near_z(), far_z() {}
camera::camera(const vector3 &_position, const vector3 &_direction,
               const vector3 &_up, double _fov, double _near_z, double _far_z)
    : position(_position), direction(_direction), up(_up), fov(_fov),
      near_z(_near_z), far_z(_far_z) {}

void camera::look_at(const vector3 &target) {
  direction = (target - position).normalized();
}
