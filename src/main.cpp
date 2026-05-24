#include "camera.hpp"
#include "matrix.hpp"
#include "object.hpp"
#include "vector3.hpp"
#include <cmath>
#include <sys/ioctl.h>
#include <terminal.hpp>
#include <unistd.h>

int main() {
  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

  terminal::enable_raw_mode();

  object cube({vector3(-1, -1, -1), vector3(1, -1, -1), vector3(1, 1, -1),
               vector3(-1, 1, -1), vector3(1, -1, 1), vector3(-1, -1, 1),
               vector3(1, 1, 1), vector3(-1, 1, 1)},
              {{0, 1, 2, 3},  // forward
               {0, 1, 4, 5},  // bottom
               {1, 2, 6, 4},  // right
               {2, 3, 7, 6},  // top
               {3, 0, 5, 7},  // left
               {5, 4, 6, 7}}, // backward
              vector3(0, 0, 0), vector3(0, 0, 0), vector3(1, 1, 1));
  
  object pyramid({vector3(-1, -1, -1), vector3(-1, -1, 1), vector3(1, -1, 1),
                   vector3(1, -1, -1), vector3(0, 1, 0)},
                  {{0, 1, 2, 3},
                   {0, 1, 4},
                   {1, 2, 4},
                   {2, 3, 4},
                   {0, 3, 4}},
                  vector3(3, 0, 0), vector3(0, 0, 0), vector3(1, 1, 1));

  camera main_camera(vector3(0, 0, -2.5), vector3(0, 0, 1.0),
                     vector3(0, 1.0, 0), 90.0, 0.1, 100.0);

  buffer screen_buffer = buffer(ws.ws_row, ws.ws_col);

  bool stop = false, devmode = false;
  while (!stop) {
    char key = 0;
    read(STDIN_FILENO, &key, 1);

    // main_camera.look_at(vector3(0, 0, 0));
    const vector3 forward = main_camera.direction.normalized(),
                  right = cross(main_camera.up, forward).normalized(),
                  up = cross(forward, right).normalized();
    const double tx = main_camera.direction.x, tz = main_camera.direction.z;
    cube.draw(screen_buffer, main_camera);
    pyramid.draw(screen_buffer, main_camera);
    if (!devmode)
      screen_buffer.print();

    switch (key) {
    case 'x':
      cube.rotation.x += 10;
      break;
    case 'X':
      cube.rotation.x -= 10;
      break;
    case 'y':
      cube.rotation.y += 10;
      break;
    case 'Y':
      cube.rotation.y -= 10;
      break;
    case 'z':
      cube.rotation.z += 10;
      break;
    case 'Z':
      cube.rotation.z -= 10;
      break;
    case 'q':
      stop = true;
      break;
    case 'w': {
      vector3 tmp(forward.x, 0, forward.z);
      tmp.normalize();
      main_camera.position += tmp * 0.1;
    } break;
    case 'a':
      main_camera.position -= right * 0.1;
      break;
    case 's': {
      vector3 tmp(forward.x, 0, forward.z);
      tmp.normalize();
      main_camera.position -= tmp * 0.1;
    } break;
    case 'd':
      main_camera.position += right * 0.1;
      break;
    case 'r':
      main_camera.position += main_camera.up * 0.1;
      break;
    case 'f':
      main_camera.position -= main_camera.up * 0.1;
      break;
    case 'h':
      main_camera.direction.x = std::cos(10.0 * 3.14159 / 180.0) * forward.x -
                                std::sin(10.0 * 3.14159 / 180.0) * forward.z;
      main_camera.direction.z = std::cos(10.0 * 3.14159 / 180.0) * forward.z +
                                std::sin(10.0 * 3.14159 / 180.0) * forward.x;
      main_camera.direction.normalize();
      break;
    case 'j':
      main_camera.direction = forward * std::cos(-10.0 * 3.14159 / 180.0) +
                              up * std::sin(-10.0 * 3.14159 / 180.0);
      main_camera.direction.normalize();
      break;
    case 'k':
      main_camera.direction = forward * std::cos(10.0 * 3.14159 / 180.0) +
                              up * std::sin(10.0 * 3.14159 / 180.0);
      main_camera.direction.normalize();
      break;
    case 'l':
      main_camera.direction.x = std::cos(-10.0 * 3.14159 / 180.0) * forward.x -
                                std::sin(-10.0 * 3.14159 / 180.0) * forward.z;
      main_camera.direction.z = std::cos(-10.0 * 3.14159 / 180.0) * forward.z +
                                std::sin(-10.0 * 3.14159 / 180.0) * forward.x;
      main_camera.direction.normalize();
      break;
    case ' ':
      devmode = !devmode;
      break;
    }
  }

  terminal::disable_raw_mode();

  return 0;
}
