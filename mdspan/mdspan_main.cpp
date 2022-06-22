#include <iostream>
#include <memory>
#include <span>
#include "experimental/mdspan"


// mdspan
// multi-dimensional span
// proposal P0009 for C++23: https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p0009r14.html
// reference impl: https://github.com/kokkos/mdspan
//
// template <
//   class T,                                 
//   class Extents,                           
//   class LayoutPolicy = std::layout_right,
//   class Accessor = std::accessor_basic
// >
// class mdspan;

namespace stdex = std::experimental;


int main()
{
  auto data1 = std::make_unique<int[]>(10);
  // equ. to std::span<int>(data1.get(), 5):
  auto M1 = stdex::mdspan(data1.get(), 5);
  for (size_t i = 0; i < M1.extent(0); i++) {
    M1(i) = 0;
  }

  constexpr size_t rows = 4;
  constexpr size_t cols = 4;

  auto data2 = std::make_unique<int[]>(rows * cols);
  // 4x4 matrix:
  auto M2 = stdex::mdspan(data2.get(), rows, cols);
  for (size_t i = 0; i < M2.extent(0); i++) {
    for (size_t j = 0; j < M2.extent(1); j++) {
      M2(i, j) = 1;
    }
  }

  auto data3 = std::make_unique<int[]>(10 * rows * cols);
  // array of 10 4x4 matrices:
  auto M3 = stdex::mdspan(data3.get(), 10, rows, cols);
  for (size_t a = 0; a < M3.extent(0); a++) {
    for (size_t i = 0; i < M3.extent(1); i++) {
      for (size_t j = 0; j < M3.extent(2); j++) {
        M3(a, i, j) = a;
      }
    }
  }

  return 0;
}
