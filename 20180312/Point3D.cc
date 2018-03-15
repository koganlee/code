 ///
 /// @file    Point3D.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-14 20:31:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int x = 0, int y = 0)
	:_x(x), _y(y) {}
    
	void print() const
	{
		cout << "(" << _x 
			 << "," << _y
			 << "):" << endl;
	}
	int getX() const { return _x;}
protected:
	int getY() const { return _y;}
private:
	int _x;
protected:
	int _y;
};

class Point3D : public Point
{
public:
	Point3D(int x, int y, int z)
	: Point(x, y), _z(z)
	{
        cout << "Point3D(int , int, int)" << endl;
	}

    void print() const
	{
		cout << "(" << getX()
			 << "," << _y
			 << "," << _z
			 << ")" << endl;
	}
private:
	int _z;
};

int main(void)
{
	Point3D pt(1, 2, 3);

	pt.print();
	pt.Point::print();
	cout << "x = "<< pt.getX() << endl;
}
