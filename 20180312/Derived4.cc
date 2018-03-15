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
	Base(int ib)
	: _ib(ib)
	{
		cout << "Base(int)" << endl;
	}

	void print() const
	{	cout << "Base::_ib = " << _ib << endl;	}

private:
	int _ib;
};

class Derived
: public Base// 接口继承
{
public:
	Derived()
	: Base(0)
	{
		cout << "Derived()" << endl;
	}

	Derived(int ib, int id)
	: Base(ib)
	, _id(id)
	{
		cout << "Derived(int,int)" << endl;
	}

	void print() const
	{
		Base::print();
		cout << "Derived::_id = " << _id << endl;
	}

private:
	int _id;
};

int main(void)
{
	Derived d1(9, 10);
	d1.print();

	return 0;
}
