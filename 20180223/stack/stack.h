 ///
 /// @file    stack.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-24 15:38:25
 ///
#ifndef STACK_H_
#define STACK_H_
#include <iostream>
#include <cstdlib>
#define SIZE 10
class Stack
{
	private:
		int elements[SIZE];
		int p;
    public:
        Stack();
		void push(int);
		void pop();
		void top();
		bool IsEmpty();
		bool IsFull();
		~Stack();
};


#endif
