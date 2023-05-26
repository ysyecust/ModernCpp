#include "myArray.hpp"
#include <functional>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>
namespace mystd {
// 函数模版
using func_type = std::function<void(int&)>;
template <typename iter_type, typename func_type = func_type>
void for_each(
    iter_type first, iter_type last,
    func_type func = [](int &elem) { ++elem; }) {
  for (auto iter = first; iter != last; ++iter) {
    func(*iter);
  }
}
template <typename T,typename allocator = std::allocator<T>> class MyVector {
public:
  template <typename T2> void outPut(const T2 &elem);
  // {
  //   std::cout<<elem<<std::endl;
  // }
};
template <typename T,typename allocator>
template <typename T2>
void MyVector<T,allocator>::outPut(const T2 &elem) {
  std::cout << elem << std::endl;
}
} // namespace mystd
int main() {

  mystd::MyVector<int> myVec;
  myVec.outPut(20);

  std::vector<int> ivec = {1, 2, 3, 4, 5};
  mystd::for_each(ivec.begin(), ivec.end());
  mystd::for_each(ivec.begin(), ivec.end(), [](int &elem) { ++elem; });
  mystd::for_each<std::vector<int>::iterator, void (*)(int &)>(
      ivec.begin(), ivec.end(), [](int &elem) { ++elem; });
  for (int elem : ivec) {
    std::cout << elem << std::endl;
  }
  
  MyArray<int> arrayI(100);
  std::cout << *arrayI.begin() << std::endl;
  std::initializer_list<int> iList{1, 2, 3, 4, 5};
  int i1 = 10;
  int i2 = 20;
  int i3 = 30;
  std::initializer_list<int *> iList1{&i1, &i2, &i3};
  MyArray<int *> arrayPi(iList1);
  for (unsigned i = 0; i < 4; ++i) {
    std::cout << *arrayPi[i] << std::endl;
  }
  return 0;
}
