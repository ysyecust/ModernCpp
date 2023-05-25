#include <iostream>
int getI(){
  return 10;
}
int getI(int i){
  return i;
}
using pf_type = int(*)(int);
void myFunc(pf_type pf, int i){
  pf(i);
}
int main(){
  int i = 100;
  int && rrefI =(i+1);//只能绑定右值
  int && rrefI2 = std::move(i);
  int && rrefI3 = getI();
  myFunc([](int i){std::cout<<i<<std::endl;std::cout<<"lambda"<<std::endl;},200);
    [](int el) {std::cout<<"asd"<<std::endl;
    std::cout<<i<<std::endl;
    std::cout<<el<<std::endl;
    
  }(200);
    []() noexcept { throw 5; }();
  
  //临时对象是右值对象 比如函数的返回值
}
