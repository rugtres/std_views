#include <iostream>
#include <valarray>


// valarray
// The idea:
// C poeple eple: OMG, FORTRAN is faster than C++ (pointer aliasing) :(
// C++: have valarray, an performance optimized numeric vector
//      with value-semantics of some sort.
// 
// overloaded operator[] for views, masks, ...
// Didn't gain much attention, kinda left-over...
// https://en.cppreference.com/w/cpp/numeric/valarray


// slice
// 1D 'selector' into a valarray, BLAS-inspired
// https://en.cppreference.com/w/cpp/numeric/valarray/slice
// 
// std::slice(start, size, stride)


// slice_array
// the 1D 'view', BLAS-inspired
// https://en.cppreference.com/w/cpp/numeric/valarray/slice_array
// 
// std::slice_array<T>
//   slice(start, size, stride)
//   T* ptr


struct Matrix
{
  explicit Matrix(int dim, int val = 0) :
    dim_(dim),
    data_(val, dim * dim)
  {}

  int& operator()(int x, int y) { return data_[dim_ * y + x]; }

  std::slice_array<int> row(std::size_t row) { return data_[std::slice(dim_ * row, dim_, 1)]; }
  std::slice_array<int> col(std::size_t col) { return data_[std::slice(col, dim_, dim_)]; }
  std::slice_array<int> diagonal() { return data_[std::slice(0, dim_, dim_ + 1)]; }
   
  // ... //

  int dim_;
  std::valarray<int> data_;
};


std::ostream& operator<<(std::ostream& os, Matrix& M)
{
  for (size_t i = 0; i < M.dim_; ++i) {
    std::valarray<int> row = M.row(i);
    for (size_t j = 0; j < row.size(); ++j) {
      os << row[j] << ' ';
    }
    os << '\n';
  }
  return os;
}


int main()
{
  Matrix M(3, 0);
  std::cout << M << '\n';
  M.diagonal() = 1;
  std::cout << M << '\n';
  return 0;
}
