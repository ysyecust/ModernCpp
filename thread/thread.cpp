#include<iostream>
#include<thread>
void test(int i,const int& refI,const int*pi){

}
int main(){
  int i=100;
  std::thread myThread1(test,i,i,&i);
  myThread1.join();
  //当传指针时，使用detach会销毁外部指针，但是这个指针还在内部引用
  std::thread myThread([](){
                       std::cout<<"Hello world"<<std::endl;
    for(int i=0;i<100000;++i){

    }
  }); 
  myThread.join();
  myThread.detach();//保证在都结束时才结束，不需要等join完成才结束主线程
  return 0;
}
