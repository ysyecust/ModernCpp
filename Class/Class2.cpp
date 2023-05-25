#include<iostream>
class Test{
  public:
    Test(unsigned old_):old(old_){}
    Test(const Test& test) = default;
    Test() = delete;
    Test& operator = (const Test& test) = default;
    ~Test()  =default;
  unsigned old;
};
int main(){
  Test test(1);
}
