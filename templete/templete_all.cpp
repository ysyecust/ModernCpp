#include <iostream>
#include <vector>
#include "myArray.hpp"
template<typename T1,typename T2>
class Test{
  public:
    Test(){
      std::cout<<"commen template"<<std::endl;
    }
};
template<typename T1,typename T2>
class Test<T1*,T2*>
{public:
Test(){
  std::cout<<"Pointer Semi-template"<<std::endl;
}};
template<typename T2>
class Test<int ,T2>{
  public:
    Test(){std::cout<<"int semi-special"<<std::endl;}
};
template<>
class Test<int, int>{
  public:
    Test(){std::cout<<"int, int complete special"<<std::endl;}
};
template<typename T>
void test(const T& parm){
  std::cout<<"void test (const T& parm"<<std::endl;
}
template<typename T>
void test(T*parm)
{std::cout<<"void test (T* parm)"<<std::endl;}
void test(double parm){
  std::cout<<"void test(double parm)"<<std::endl;
}
int main(){
  // test(100);
  // double s = 234.0;
  // int i=100;
  // int * p = new int(100); 
  // int const * p1 = new int(100); 
  // test(s);
  // test(&i); 
  // test(p); 
  // test(p1); 
  Test<int*,int*> test;
  Test<int,double> test2;
}
