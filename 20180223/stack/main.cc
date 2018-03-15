#include "stack.h"
using  std::cout;
using  std::endl;
int main()
{
  Stack stack;
  stack.push(10);
  stack.push(12);
  stack.push(14);
  stack.top(); 
  stack.pop();
  stack.top();
  return 0;
}
