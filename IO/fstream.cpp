#include <cstdio>
#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

int main (){
  // std::fstream fs("hello");
  // std::ifstream ifs;
  // std::ofstream ofs;
  // ifs.open("hello");
  // ifs.close();//文件存储在内核区
  std::ofstream ofs("num.txt",std::ios::app);//继续往后面写
  if (ofs.is_open()){
    ofs<<"hello world"<<std::endl;
    ofs.close();
  }
  std::string fileName;
  std::string fileContent;
  while(std::cin>>fileName,!std::cin.eof()){
    if (std::cin.bad()){
      throw std::runtime_error("cin is corrupted");
    }
    std::ifstream ifs(fileName);
    if (ifs.is_open()){
      while (std::getline(ifs,fileContent)) {
        std::cout<<fileContent<<std::endl;
      }
      if (ifs.bad()){
      throw std::runtime_error("ifs is corrupted");
        
      }
      ifs.close();
    }
    else{
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"file not exist, please try again"<<std::endl;
      continue;
    }
  }
  std::cout<<"process complete"<<std::endl;
}
