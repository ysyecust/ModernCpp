#include <iostream>
#include <thread>
#include <unistd.h>

class Test{
public:
  Test(int i_):i(i_){
    std::cout<<std::this_thread::get_id()<<std::endl;
  }
  Test(const Test& test){
    std::cout<<"Test(const Test& test)"<<std::endl;
  }
  int i;
};
void test(Test& str){
  std::cout<<"child thread id is: "<<std::this_thread::get_id()<<std::endl;
  str.i = 200;

}
int main(){
  std::cout<<"main thread id is : "<<std::this_thread::get_id()<<std::endl;
  Test t(100);
  std::thread myThread(test,t);
  myThread.detach();
    usleep(1000);
  

}
