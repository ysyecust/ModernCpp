#include <cstring>
#include <iostream>
//对象移动，转移权限
class Test{
  public:
    Test() = default;
    Test(const Test& test){
      if(test.str){
        str = new char[strlen(test.str)+1]();
        strncpy(str,test.str,strlen(test.str)+1);

      }
      else{
        str = nullptr;
      }
    }//赋值构造函数
    Test(Test&& test){
      if (test.str){
        str = test.str;
        test.str = nullptr;
      }
      else{
        str = nullptr;
      }
    }
    Test& operator=(const Test& test){
      if (this==&test){//自赋值情况
        return *this;
      }
      if (str){
        delete[] str;
        str =  nullptr;
      }
      if (test.str){
        str = new char[strlen(test.str)+1]();
        strncpy(str,test.str,strlen(test.str)+1);
        
      }
      else{
        str = nullptr;

      }
      return *this;
    }
    Test& operator=(Test && test){
      if (this==&test){//自赋值情况
        return *this;
      }
      if (str){
        delete[] str;
        str =  nullptr;
      }
      if (test.str){
       str = test.str;
      }
      else{
        str = nullptr;

      }
      return *this;}
  private:
    char* str = nullptr;
};
Test makeTest(){
  Test t;
  return t;
}
int main(){
  Test t = makeTest();
  return 0 ;
}
