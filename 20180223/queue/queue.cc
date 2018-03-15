 ///
 /// @file    queue.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-24 22:38:31
 ///
 
#include "queue.h"
using std::cout;
using std::endl;

Queue::Queue()
{
   frt = 1;
   tail = 0;
}

void Queue::push(int num)
{
    if(isfull())
	{
       cout << "Front of the Queue is full.\n";
	   return;
	} 
     tail = (tail + 1) % (SIZE + 1);
     element[tail] = num;
}

bool Queue::isfull()
{
	  return (tail + 2) % (SIZE + 1) == frt;
}
void Queue::pop()
{
   if(isempty())
   {
      cout << "Queue is empty.\n";
      return;
   }
   frt = ((frt + 1) % (SIZE + 1)); 
}

void Queue::front()
{
  if(isempty())
  {
  cout << "Front of the queue is empty.\n";
	  return;
  }
  cout << "front=" << element[frt] << endl;

}

bool Queue::isempty()
{
	return (tail + 1) % (SIZE + 1) == frt;
}

void Queue::rear()
{
   if(isempty()) {
	 cout << "Rear of the queue is empty.\n";
     return;
   }
   cout << "rear=" << element[tail] << endl;

}
Queue::~Queue()
{

}

