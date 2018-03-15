 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-12 16:37:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	int func(int i)
	{
		return _ix;
	}
protected:
	int _ix;
};

class Derived
: public Base
{
public:
	int func()
	{
		_ix = 10;//对于数据成员而言，一样存在隐藏这种机制
		//Base::_ix = 20;
		cout << "Base::_ix = " << Base::_ix << endl;
		cout << "Derived::_ix = " << Derived::_ix << endl;
		cout << "_ix = " << _ix << endl;
		return _ix;
	}
private:
	int _ix;
};

int main(void)
{
	Derived d;
	//d.func(1);//error,即使参数不同的情况下，也访问不到基类的同名函数 (隐藏)
	
	cout << d.func() << endl;
	cout << d.Base::func(1) << endl;
	

	return 0;
}
