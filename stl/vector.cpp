#include <deque>
#include <iostream>
#include <iterator>
#include <set>
#include <stdexcept>
#include <vector>
int main() {
  std::vector<int> ivec{1, 2, 3, 4};
  std::vector<int> ive4(5, 0);
  std::deque<int> ideque{1, 2, 3, 4, 5};
  std::set<int> iset{1, 2, 3, 4, 5};
  std::vector<int> ivec2(ideque.cbegin(), ideque.cend());
  auto iter = ivec2.insert(++ivec2.begin(), 100);
  std::cout << std::distance(ivec2.begin(), iter) << std::endl;
  auto iter2 = ivec2.erase(ivec2.begin(), ivec2.begin() + 3);
  for (int elem : ivec2) {
    std::cout << elem << std::endl;
  }
  std::vector<int> ivec3(iset.cbegin(), iset.cend());
  for (int elem : ivec) {
    std::cout<<elem<<std::endl;
  }
  //遍历
  int& i= ivec.front();
  std::cout<<i<<std::endl;
  i = 20;
  std::cout<<ivec.at(0)<<std::endl;
  std::cout<<ivec.size()<<std::endl;
  std::cout<<ivec.capacity()<<std::endl;
  std::cout<<ivec.max_size()<<std::endl;
  
  // try{
  // std::cout<<ivec.at(3)<< std::endl;
  // // std::cout<<ivec[10]<<std::endl;
  // }
  // catch(const std::out_of_range &except)
  // {
  //   std::cout<<except.what() <<std::endl;
  // }
  return 0;
}
