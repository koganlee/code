 ///
 /// @file    stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-24 15:38:15
 ///
 
#include "stack.h"
Stack::Stack()
{
    p = 0; 
}

void Stack::push(int num)
{
   if(IsFull())
   {
	std::cout << "Stack is IsFull.\n";
    return;
   }
  elements[p++] = num; 
}

bool Stack::IsFull()
{
    if( p == SIZE)
	{
		return true;
     }
	else
		return false;
}

void Stack::pop()
{
   if(IsEmpty())
	{
	   std::cout << "Stack is IsEmpty.\n";
       return;
	}
    p--;
}


void Stack::top()
{
   if(IsEmpty())
	{
	   std::cout << "Stack is empty.\n";
       return ;
	}
    std::cout << "top =" << elements[p - 1] << std::endl;
}

bool Stack::IsEmpty()
{
	 if( p == 0)
		 return true;
	 else
         return false;      
}


Stack::~Stack()
{
}



