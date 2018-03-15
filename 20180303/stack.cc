 ///
 /// @file    stack.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-07 16:35:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;
const int MAX = 10;
template<typename T, int kSize = 10>
class Stack
{
public:
    Stack();
	bool empty();
	bool full();
	void gettop();
	void push(const T & data);
	void pop();
private:
	int top;
	T array[MAX];
//    T * _array;
};


template <typename T, int kSize>
Stack<T, kSize>::Stack()
{
    top = -1;
}

template<typename T, int kSize>
void Stack<T, kSize>::push(const T & num)
{
   if(!full())
   {
     array[++top] = num;
   }
   else
   {
	 cout << "The Stack is full.\n";
   }
}


template<typename T, int kSize>
void Stack<T, kSize>::pop()
{
    if(empty())
	{
       cout << "The Stack is empty.\n";
	}
    else  {
	--top;
	}
}

template<typename T, int kSize>
bool Stack<T, kSize>::full() 
{
    return  top == MAX - 1;
}



template<typename T, int kSize>
bool Stack<T, kSize>::empty()
{
   return top == -1;
}

template<typename T, int kSize>
void  Stack<T, kSize>::gettop()
{
   if(!empty())
   {
     cout << "Top is :" <<  array[top] << endl;
   }
   else
   {
	   cout << "The Stack is empty.\n";
   }
}

int main()
{
	Stack<int>stack;
    int j= 0;
	for(int i = 0; i < MAX + 1; ++i)
	{
         stack.push(j);
		 ++j;
	}

	for(int i = 0; i < MAX + 1; ++i)
	{
	    stack.gettop();
		stack.pop();
	}
}
