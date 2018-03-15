 ///
 /// @file    multiDerived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-12 15:20:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	void print() const
	{	cout << "A::print()" << endl;	}
};

class B
{
public:
	void print() const
	{	cout << "B::print()" << endl;	}
};

//多基派生中的问题1： 成员名访问冲突的问题
//
//解决方案：直接使用作用域限定符访问

class C
: public A
, public B 
{
public:
	void show() const
	{	cout << "C::show()" << endl;	}

#if 0
	void print() const
	{	cout << "C::print()" << endl;	}
#endif
};

int main(void)
{
	C c;
	//c.print();
	c.A::print();
	c.B::print();
	return 0;
}
