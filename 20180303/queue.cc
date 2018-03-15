 ///
 /// @file    queue.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-09 14:24:59
 ///
 
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
const int MAX = 10;

template<typename T,int kSize = 10>
class Queue
{
public:
   Queue();
   ~Queue();
   bool isempty();
   bool isfull();
   void  getfront();
   void  getrear();
   void enqueue(const T & item);
   void dequeue();
private:
   T *_array;
   int front;
   int rear;
};


template<typename T, int kSize>
Queue<T, kSize>::Queue(): _array(new T[kSize]), front(0), rear(0)
{
}


template<typename T, int kSize>
Queue<T, kSize>::~Queue()
{
   delete []_array;
}

template<typename T, int kSize>
void Queue<T, kSize>::enqueue(const T & item)
{
    if(!isfull())
	{
       *(_array+rear) = item;
       ++rear;
	 //  rear %= kSize;
	}
	else {
	cout << "The queue is full.\n";
	}
}

template<typename T, int kSize>
void Queue<T, kSize>::dequeue()
{ 
   if(!isempty())
   {
      ++front;
	  front %= kSize;
   }
   else  {
   cout << "The Queue is empty.\n";
   }
}

template<typename T, int kSize>
bool Queue<T, kSize>::isfull()
{
    return  (rear + 1) % kSize  == front;
}

template<typename T, int kSize>
bool Queue<T, kSize>::isempty()
{
	return rear == front;
}

template<typename T, int kSize>
void Queue<T, kSize>::getfront() 
{
  if(!isempty())
   {
      cout << "front:" << *(_array + front) << endl;
   }
   else{
      cout << "The Queue is empty.\n";
   }
}

template<typename T, int kSize>
void Queue<T, kSize>::getrear() 
{
   if(!isempty())
   {
      cout << "rear:" << *(_array + rear - 1) << endl;
   }
   else{
      cout << "The Queue is empty.\n";
   }
}


int main()
{
   Queue<int, 10>queue;
  
   int j = 1;
   for(int i = 0; i < MAX + 10; ++i)
   {
      queue.enqueue(j);
	  queue.getrear();
	  ++j;
   }
   for(int i = 0; i < MAX + 1; ++i)
   {
	  queue.getfront();
      queue.dequeue();
   }
}
