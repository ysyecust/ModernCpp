#include <iostream>
#include <memory>
void myFunc(std::shared_ptr<int> sharedI){}
int main (int argc, char *argv[]) {
  int * pi= new int(100);
  std::shared_ptr<int> sharedI = std::make_shared<int>(100);
  std::cout<<sharedI.unique()<<std::endl;
  std::cout<<sharedI.use_count()<<std::endl;
  std::shared_ptr<int> sharedI2(sharedI);
  std::cout<<sharedI.unique()<<std::endl;
  std::cout<<sharedI.use_count()<<std::endl;
  sharedI2.reset();
  std::cout<<sharedI.unique()<<std::endl;
  std::cout<<sharedI.use_count()<<std::endl;
  std::shared_ptr<int> sharedI3 = std::make_shared<int>(500);
  sharedI.swap(sharedI3);
  std::cout<<*sharedI3.get()<<std::endl;
  std::cout<<*sharedI<<std::endl;
  std::shared_ptr<int> sharedI_list(new int [100]);
  std::cout<<sharedI.get()[10]<<std::endl;
  myFunc(sharedI);
  std::cout<<sizeof(sharedI)<<std::endl;
  return 0;
}
