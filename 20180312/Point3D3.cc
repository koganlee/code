 ///
 /// @file    Point3D.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-12 14:50:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	int getX() const {	return _ix;	}
protected:
	int getY() const {	return _iy;	}

private:
	//对于基类的私有成员，在派生类内部不能进行访问
	int _ix;
protected:	
	int _iy;
};

class Point3D
: Point
//当以private方式继承时，基类的非私有成员在派生类内部都是private访问权限
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void print() const
	{
		cout << "(" << getX() 
			 << "," << _iy   //protected 基类受保护的成员，可以直接在派生类内部进行访问
			 << "," << _iz
			 << ")" << endl;
	}

private:
	int _iz;
};


class Point4D
:public Point3D
{
public:

	void display() const
	{
		cout << "(" << getX() 
			 << endl;
	}
	
protected:
	int _im;

};

int main(void)
{
	Point3D pt(1, 2, 3);

	pt.print();//基类的print方法被隐藏
	//pt.Point::print();//error 基类的print方法在派生类内部是private，无法在派生类之外访问
	//cout << "ix = " << pt.getX() << endl;//error, private 
	//pt._iy = 10;//protected的权限是开放给派生内部进行访问
	//pt.getY();

	return 0;
}
