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
	A()
	{	cout << "A()" << endl;}
	void print() const
	{	cout << "A::print()" << endl;	}
};

class B
{
public:
	B()
	{	cout << "B()" << endl;	}


	void display() const
	{	cout << "B::display()" << endl;	}
};


class C
: public A
, public B 
{
public:
	C()
	: B()
	, A()
	{
		cout << "C()" << endl;
	}

	void show() const
	{	cout << "C::show()" << endl;	}
};

int main(void)
{
	C c;
	c.print();
	c.display();
	c.show();
	return 0;
}
