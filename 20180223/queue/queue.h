 ///
 /// @file    queue.h
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-24 22:34:27
 ///
#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
using std::cout;
using std::endl;
typedef int elem;

class Queue
{
private:
	enum{SIZE = 10};
	elem element[SIZE + 1];
	elem frt;
	elem tail;
public:
	Queue();
	void push(int);
	void pop();
	void front();
	void rear();
	bool isempty();
	bool isfull();
	~Queue();
};

#endif
