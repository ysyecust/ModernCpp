#include <iostream>
#include <stack>
#include <queue>
int main(){
  std::stack<int>istack;
  istack.push(1);
  istack.push(2);
  std::cout<<istack.top()<<std::endl;
  std::queue<int>iQueue;
  iQueue.push(1);
  iQueue.push(2);
  std::cout<<iQueue.front()<<std::endl;
}
