#include <iostream>
#include <memory>
void myfunc(std::unique_ptr<int> uniqueI)
{
  std::shared_ptr<int> sharedI(std::move(uniqueI));
}
int main() {
  std::unique_ptr<int> uniqueI = std::make_unique<int>(100);
  std::unique_ptr<int> uniqueI2(std::move(uniqueI));
  std::unique_ptr<int> uniqueI3(uniqueI);
}

