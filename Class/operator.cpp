#include <iostream>
#include <ostream>
#include <string>
#include <vector>
class Test {
  friend std::ostream &operator<<(std::ostream &os, const Test &test);
  friend std::istream &operator>>(std::istream &is, Test &test);

public:
  void operator++() { ++count; }
  int operator[](unsigned i) { return ivec[i]; }
  void operator()() { std::cout << "Hello" << std::endl; }
  Test operator+(const Test &test) {
    count += test.count;
    return *this;
  }
  // Test& operator=(const Test& test){
  //   if (this ==&test)
  //     return *this;
  //   count = test.count;
  //   name = test.name;;
  //   return *this;
  // }
  Test &operator=(const Test& test) = default;
  unsigned count = 0;
  std::string name = "xinhui";
  std::vector<int> ivec{1, 2, 3, 4, 5, 6};
};
std::ostream &operator<<(std::ostream &os, const Test &test) {
  os << test.name << std::endl;
  return os;
}
std::istream &operator>>(std::istream &is, Test &test) {
  is >> test.name;
  return is;
}
int main() {
  Test test;
  ++test;
  std::cout << test.count << std::endl;
  test();
  std::cout << test;
}
