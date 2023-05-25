#include <iostream>
#include <string>
class Test {
public:
  Test(int i_) : i(i_) {}
  Test(){
    this->i = 100;
  }
  int printi(){return i;}
private:
  int i;
};
int main() {
  int *pi = new int;
  std::cout << *pi << std::endl;
  std::string *pString = new std::string("hello");

  std::cout << *pString << std::endl;
  int *pi_list = new int[100];
  std::cout << pi_list[20] << std::endl;
  delete pi;
  delete pString;
  delete[] pi_list;
  Test* pTest = new Test[100];
  delete[] pTest;
  std::cout<<pTest->printi()<<std::endl;
  return 0;
}
