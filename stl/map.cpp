#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
int main() {
  std::map<int, std::string> int_map;
  int_map.insert(std::pair<int, std::string>(10, "asd"));
  std::vector<int> ivec{1, 2, 3, 4, 5, 6};
  std::sort(ivec.begin(), ivec.end(),
            [](int elem1, int elem2) { return elem1 > elem2; });
  std::cout << std::binary_search(
                   ivec.cbegin(), ivec.cend(), 5,
                   [](int elem1, int elem2) { return elem1 > elem2; })
            << std::endl;
  for (auto num : ivec) {
    std::cout << num << std::endl;
  }
  std::vector<int> ivec1{1,2,3,3,4,5,6,7};
  auto iter = std::unique(ivec1.begin(),ivec1.end());
  for (auto num : ivec1) {
    std::cout << num << std::endl;
  }
  
  for (auto it = ivec1.cbegin();it!=iter;++it) {
    std::cout << *it << std::endl;
  }

}
