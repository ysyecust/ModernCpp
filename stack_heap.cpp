#include <iostream>
#include <vector>
#include <version>

std::vector<int> iVec;
std::vector<int *> iVec_heap;
int test() {
  /*
  函数内部空间是栈内存
  */
  int i = rand();
  int *pi = new int(rand());
  iVec.push_back(i);
  // 调用堆内存
  iVec_heap.push_back(pi);
  static unsigned funcCallCount = 0;
  funcCallCount++;
  return funcCallCount;
}
int main() {
  test();
  test();
  unsigned testFunCallCount = test();
  std::cout << testFunCallCount << std::endl;
  return 0;
}
