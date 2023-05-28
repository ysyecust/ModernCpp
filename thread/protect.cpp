#include <iostream>
#include <thread>
#include <mutex>
 std::mutex myMutex;
  //互斥锁
unsigned g_num = 0;
void test() {
  std::lock_guard<std::mutex> lg(myMutex);
  for (unsigned i = 0; i < 10000000; ++i)
    ++g_num;
  myMutex.unlock();
}
// 数据保护
int main() {
  std::thread myThread(test);
  myMutex.lock();
  for (unsigned i = 0; i < 10000000; ++i) {
    ++g_num;
  }
  myMutex.unlock();
  myThread.join();
  std::cout<<g_num<<std::endl;
  return 0;
}
