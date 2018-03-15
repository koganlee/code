 ///
 /// @file    DerivedDestructor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-12 16:24:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	A(int ix)
	: _ix(ix)
	{
		cout << "A(int)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _ix;
};

class B
{
public:
	B(){	cout << "B()" << endl;	}
	~B(){	cout << "~B()" << endl;	}
};

class C
: public A
{
public:
	C(int ix, int iy)
	: A(ix)
	, _b()
	, _iy(iy)
	{
		cout << "C(int,int)" << endl;
	}

	//当派生类对象的析构函数执行完毕之后，会自动调用基类的析构函数，销毁基类部分
	~C()
	{
		cout << "~C()" << endl;
	}
private:
	B _b;
	int _iy;
};

int main(void)
{
	C c(1, 2);

	return 0;
}
