 ///
 /// @file    main.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-24 23:10:21
 ///
 
#include "queue.h"
using std::cout;
using std::endl;
int main()
{
   Queue queue;
   queue.push(1);
   queue.rear();
   queue.push(2);
   queue.rear();
   queue.push(3);
   queue.rear();
   queue.push(4);
   queue.rear();
   queue.push(20);
   queue.pop();
   queue.front();
   return 0;
}
