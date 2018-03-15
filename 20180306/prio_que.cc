 ///
 /// @file    pro_que.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-12 22:26:04
 ///
 
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

void test(void)
{
  int array[] =  { 3, 5, 6, 1, 4, 9, 7, 8, 0, 2};
  priority_queue<int,std::vector<int>, std::greater<int> >pque;
 
  for(int idx = 0; idx != 10; ++idx)
  {
	  pque.push(array[idx]);
	  cout << pque.top() << endl;
  }
  while(!pque.empty())
  {
	  cout << pque.top() << endl;
	  pque.pop();
  }
}

int main()
{
  test();
  return 0;
}

