#include <iostream>
int main() {
  int m = 0;
  int n = 0;
  [&, n](int a) mutable { m = ++n + a; }(4);
  std::cout << m << std::endl << n << std::endl;
}
