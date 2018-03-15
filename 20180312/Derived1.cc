 ///
 /// @file    Derived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-12 16:06:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

private:
	int _ib;
};

class Derived
: public Base// 接口继承
{
public:
	Derived()
	{
		cout << "Derived()" << endl;
	}

	Derived(int id)
	: _id(id)
	{
		cout << "Derived()" << endl;
	}

private:
	int _id;
};

int main(void)
{
	Derived d;
	Derived d2;

	return 0;
}
