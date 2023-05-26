#include <atomic>
#include <iostream>
#include <memory>
class B;
class A {
public:
  // std::shared_ptr<B> sharedB;
  std::weak_ptr<B> weakB;
};
class B {
public:
  std::shared_ptr<A> sharedA;
};
int main() {
  std::shared_ptr<int> sharedI = std::make_shared<int>(100);
  std::cout << sharedI.use_count() << std::endl;
  std::weak_ptr<int> weakI(sharedI);
  std::cout << sharedI.use_count() << std::endl;
  std::shared_ptr<A> sharedA = std::make_shared<A>();
  std::shared_ptr<B> sharedB = std::make_shared<B>();
  sharedA->weakB = sharedB;
  sharedB->sharedA = sharedA;
  std::cout<<sharedB.use_count()<<std::endl;
  
}
