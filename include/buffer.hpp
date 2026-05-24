#ifndef __BUFFER_HPP__
#define __BUFFER_HPP__

#include "vector3.hpp"
#include <vector>

const double SYMBOL_ASPECT = 0.45; // 9/20

class buffer {
public:
  std::size_t rows, cols;
  std::vector<std::vector<char>> data;
  std::vector<std::vector<double>> depth;

  buffer();
  buffer(std::size_t rows, std::size_t cols);
  buffer(std::size_t rows, std::size_t cols,
         std::vector<std::vector<char>> data);

  std::vector<std::vector<char>>::iterator begin();
  std::vector<std::vector<char>>::iterator end();

  std::vector<char> &operator[](std::size_t i);

  void draw_line(vector3 point[2]);
  void print();
};

#endif
