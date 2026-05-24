#include "buffer.hpp"
#include "terminal.hpp"
#include <iostream>

buffer::buffer() : rows(0), cols(0), data(0) {}
buffer::buffer(std::size_t rows, std::size_t cols)
    : rows(rows), cols(cols), data(rows, std::vector<char>(cols, ' ')) {}
buffer::buffer(std::size_t rows, std::size_t cols,
               std::vector<std::vector<char>> data)
    : rows(rows), cols(cols), data(rows, std::vector<char>(cols, ' ')) {
  for (std::size_t i = 0; i < rows && i < data.size(); i++)
    for (std::size_t j = 0; j < cols && j < data[i].size(); j++)
      this->data[i][j] = data[i][j];
}

std::vector<std::vector<char>>::iterator buffer::begin() {
  return data.begin();
}
std::vector<std::vector<char>>::iterator buffer::end() { return data.end(); }

std::vector<char> &buffer::operator[](std::size_t i) { return data[i]; }

void buffer::draw_line(vector3 point[2]) {
  int x[2] = {(int)point[0].x, (int)point[1].x},
      y[2] = {(int)point[0].y, (int)point[1].y};

  const int delta_x = abs(x[1] - x[0]), delta_y = abs(y[1] - y[0]);
  const int sign_x = x[1] > x[0] ? 1 : -1, sign_y = y[1] > y[0] ? 1 : -1;
  int error = delta_x - delta_y;
  while (true) {
    if (x[0] >= 0 && x[0] < cols && y[0] >= 0 && y[0] < rows)
      data[y[0]][x[0]] = '*';
    if (x[0] == x[1] && y[0] == y[1])
      break;
    int error2 = 2 * error;
    if (error2 > -delta_y) {
      error -= delta_y;
      x[0] += sign_x;
    }
    if (error2 < delta_x) {
      error += delta_x;
      y[0] += sign_y;
    }
  }
}

void buffer::print() {
  for (std::size_t i = 0; i < rows; i++)
    for (std::size_t j = 0; j < cols; j++) {
      std::cout << curmov(i, j) << data[i][j];
      data[i][j] = ' ';
    }
  std::cout << std::flush;
}
