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
	{	cout << "A::print() _ia = " << _ia << endl;	}

	void setA(int ia)
	{	_ia = ia;	}
private:
	int _ia;
};

class B
: virtual public A
{
};

//多基派生中的问题2： 菱形继承时，产生的存储二义性问题
//
//解决方案：采用虚继承

class C
: virtual public A
{
public:
	void show() const
	{	cout << "C::show()" << endl;	}

};

class D
: public B
, public C
{

};

int main(void)
{
	D d;
	d.setA(10);
	d.print();
	//d.B::setA(19);
	//d.C::setA(10);
	//d.B::print();
	//d.C::print();
	return 0;
}
