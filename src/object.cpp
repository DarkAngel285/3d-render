#include "object.hpp"
#include "buffer.hpp"
#include "math.hpp"
#include "matrix.hpp"
#include "vector4.hpp"
#include <algorithm>
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <sys/ioctl.h>

object::object()
    : vertices(0), faces(0), position(vector3()), rotation(vector3()),
      scale(vector3()) {}
object::object(std::vector<vector3> vertices,
               std::vector<std::vector<std::size_t>> faces)
    : vertices(vertices), faces(faces), position(), rotation(), scale(1, 1, 1) {
}
object::object(std::vector<vector3> vertices,
               std::vector<std::vector<std::size_t>> faces, vector3 position,
               vector3 rotation, vector3 scale)
    : vertices(vertices), faces(faces), position(position), rotation(rotation),
      scale(scale) {}

vector3 projection_division(const vector4 &hv) {
  if (hv.w != 0) {
    return vector3(hv.x / hv.w, hv.y / hv.w, hv.z / hv.w);
  } else {
    std::cerr << "It's a radius vector\n\r";
    return vector3(hv.x, hv.y, hv.z);
  }
}

vector3 viewport_transform(const vector3 &v, const double &screen_width,
                           const double &screen_height) {
  return vector3((v.x + 1.0) * (screen_width / 2.0),
                 (-v.y + 1.0) * (screen_height / 2.0), v.z);
}

std::vector<double> calculate_bc(const vector4 &hv) {
  return std::vector<double>{hv.w + hv.x, hv.w - hv.x, hv.w + hv.y,
                             hv.w - hv.y, hv.w + hv.z, hv.w - hv.z};
}

std::bitset<6> calculate_outcode(const std::vector<double> &bc) {
  std::bitset<6> outcode;
  for (short i = 0; i < 6; i++) {
    outcode[i] = bc[i] <= 0;
  }
  return outcode;
}

int line_clipping(vector4 hv[2]) {
  std::vector<double> bc[2] = {calculate_bc(hv[0]), calculate_bc(hv[1])};
  std::bitset<6> outcode[2] = {calculate_outcode(bc[0]),
                               calculate_outcode(bc[1])};
  double t_in = 0.0, t_out = 1.0, t_hit;
  if ((outcode[0] & outcode[1]) != 0)
    return 0;
  if ((outcode[0] | outcode[1]) == 0)
    return 1;
  for (short i = 0; i < 6; i++) {
    if (bc[1][i] < 0) {
      t_hit = bc[0][i] / (bc[0][i] - bc[1][i]);
      t_out = std::min(t_out, t_hit);
    } else if (bc[0][i] < 0) {
      t_hit = bc[0][i] / (bc[0][i] - bc[1][i]);
      t_in = std::max(t_in, t_hit);
    }
    if (t_in > t_out)
      return 0;
  }

  vector4 tmp(hv[0]);

  if (outcode[0] != 0) {
    tmp.x = hv[0].x + t_in * (hv[1].x - hv[0].x);
    tmp.y = hv[0].y + t_in * (hv[1].y - hv[0].y);
    tmp.z = hv[0].z + t_in * (hv[1].z - hv[0].z);
    tmp.w = hv[0].w + t_in * (hv[1].w - hv[0].w);
  }

  if (outcode[1] != 0) {
    hv[1].x = hv[0].x + t_out * (hv[1].x - hv[0].x);
    hv[1].y = hv[0].y + t_out * (hv[1].y - hv[0].y);
    hv[1].z = hv[0].z + t_out * (hv[1].z - hv[0].z);
    hv[1].w = hv[0].w + t_out * (hv[1].w - hv[0].w);
  }

  hv[0] = tmp;
  return 1;
}

void object::draw(buffer &target_buffer, const camera &target_camera) {
  const matrix model = matrices::model(position, rotation, scale),
               view = matrices::view(target_camera.position,
                                     target_camera.direction, target_camera.up),
               projection = matrices::perspective_projection(
                   target_camera.fov, target_camera.near_z, target_camera.far_z,
                   target_buffer.cols, target_buffer.rows);
  for (std::vector<std::size_t> face : faces) {
    for (std::size_t i = 0; i < face.size(); i++) {
      vector3 v[2] = {vertices[face[(i == 0 ? face.size() : i) - 1]],
                      vertices[face[i]]};
      vector4 hv[2] = {vector4(v[0], 1), vector4(v[1], 1)};
      hv[0] = projection * view * model * hv[0];
      hv[1] = projection * view * model * hv[1];
      if (line_clipping(hv)) {
        v[0] = viewport_transform(projection_division(hv[0]),
                                  target_buffer.cols, target_buffer.rows);
        v[1] = viewport_transform(projection_division(hv[1]),
                                  target_buffer.cols, target_buffer.rows);
        target_buffer.draw_line(v);
      }
    }
  }
}
