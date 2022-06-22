#include <iostream>
#include <vector>
#include <span>

// span<T>
// Basically an iterator pair or a ptr + size pair
// 
// 1D view into contineous memory
// 
// https://en.cppreference.com/w/cpp/container/span
//
// template <
//   class T,                                 
//   size_t Extent,                           
// >
// class span;


void print(const char* msg, const std::span<int>& span) {
  std::cout << msg;
  for (const auto x : span) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}


int main()
{
  int a[] = { 0,1,2,3,4,5,6,7,8,9 };
  auto s = std::span(a, std::size(a));    // why we should switch from container-member function to free ones
  print("owner: ", s);

  for (auto& x : s) { x += 1; }
  print("+1: ", s);

  auto head = std::span(a, 3);
  print("head: " , head);

  auto mid = s.subspan(3, 4);
  print("mid: ", mid);

  auto tail = std::span<int, 3>(std::end(a) - 3, 3);    // compile-time extent
  print("tail: ", tail);

 
  return 0;
}
