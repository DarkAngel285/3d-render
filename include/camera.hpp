#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "vector3.hpp"

class camera {
public:
  vector3 position, direction, up;
  double fov, near_z, far_z;

  camera();
  camera(const vector3 &_position, const vector3 &_direction,
         const vector3 &_up, double _fov, double _near_z, double _far_z);

  void look_at(const vector3 &target);
};

#endif
