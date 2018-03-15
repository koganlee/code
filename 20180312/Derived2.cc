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
#if 1
	Base()
	{
		cout << "Base()" << endl;
	}
#endif

	Base(int ib)
	: _ib(ib)
	{
		cout << "Base(int)" << endl;
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

#if 0
	Derived(int id)
	: _id(id)
	{
		cout << "Derived()" << endl;
	}
#endif

private:
	int _id;
};

int main(void)
{
	Derived d;

	return 0;
}
