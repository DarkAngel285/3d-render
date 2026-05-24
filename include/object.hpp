#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include "buffer.hpp"
#include "camera.hpp"
#include "vector3.hpp"
#include <vector>

class object {
public:
  std::vector<vector3> vertices;
  std::vector<std::vector<std::size_t>> faces;
  vector3 position, rotation, scale;

  object();
  object(std::vector<vector3> vertices,
         std::vector<std::vector<std::size_t>> faces);
  object(std::vector<vector3> vertices,
         std::vector<std::vector<std::size_t>> faces, vector3 position,
         vector3 rotation, vector3 scale);

  void draw(buffer &target_buffer, const camera &target_camera);
};

#endif
