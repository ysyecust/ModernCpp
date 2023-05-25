#include <iostream>

struct Ctest{
  int i;
  int i2;
};
struct CPPtest{
  public:
    CPPtest(int i_,int i2_,int i3):i(i_),i2(i2_),pi(new int(i3)){}
    CPPtest(const CPPtest& cppTest):i(cppTest.i),i2(cppTest.i2),pi(new int(*cppTest.pi)){}
    ~CPPtest(){delete pi;}
  
  int i;
  int i2;
  int *pi;
  
};
int main(){
  CPPtest test(1,2,3);
  std::cout<<test.i<<std::endl;
  std::cout<<test.i2<<std::endl;

}
