#include <iostream>
#include<fstream>
#include <ostream>
#include<sstream>
#include <stdexcept>
class Test{
  friend std::ostream& operator<<(std::ostream& os, const Test& test);
};
int main(){
  std::fstream fsl; 
  int i = 10;
  while(std::cin>>i,!std::cin.eof()){
    if(std::cin.bad()){
      throw std::runtime_error("cin is corrupted");
    }
    if (std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"data format error, please try again"<< std::endl;
      continue;
    }
    std::cout<<i<<std::endl;
  }
  std::cout<<"process complete"<<std::endl;
  return 0;
}
