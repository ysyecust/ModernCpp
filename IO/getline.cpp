#include <iostream>
#include <string>

int main(){
  std::string str;
  while (std::getline(std::cin,str),!std::cin.eof()){
    if (std::cin.bad()){
      throw std::runtime_error("cin is corrupted");
    }
    std::cout<<str<<std::endl;
  }
}
