#include <ios>
#include<iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

int main(){
  std::string str("12");
  std::stringstream strStream(str);
  int i = 0;
  strStream>>i;
  if (strStream.bad()){
    throw std::runtime_error ("strStream is corrupted");
  }
  else if (strStream.fail())
  {
  strStream.clear();
  strStream.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::cout<<"steing format error"<<std::endl;
}
  else {
    std::cout<<i<<std::endl;
  }
  int srcI = 100;
  std::stringstream strStream1;
  strStream1<<srcI<<std::endl;
  if (strStream.bad()){
    throw std::runtime_error("strStream is corrupted");
  }
  else {
    std::cout<<strStream.str()<<std::endl;
  }
  std::string srcString("hello hello dsdsds");
  std::string destString;
  std::stringstream strStream2(srcString);
  while(strStream2>>destString){
    std::cout<<destString<<std::endl;
  }
  if(strStream.bad()){
    throw std::runtime_error("strStream is corrupted");
  }
 return 0; 
}
