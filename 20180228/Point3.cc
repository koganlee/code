 ///
 /// @file    Point3.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-03 09:28:45
 ///
 
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
class Point;
class Line
{
public:
    Line(int z = 0) : _z(z)
	{
        cout << "Line(int) .\n";
	}

	float distance(const Point & lhs, const Point &rhs);
	void  setPoint( Point & rhs, int x, int y);
private:
    int _z;
};

class Point
{
  friend class Line;
public:
  Point(int x = 0, int y = 0) : _x(x), _y(y)
  {
     cout << "Point:" << endl;
  }
  void print() const
  {
    cout << "(" << _x << "," << _y << ")" << endl;
  }
private:
  int _x;
  int _y;
};
float Line::distance(const Point & lhs, const Point &rhs)
	{
        return  sqrt((lhs._x - rhs._x)*(lhs._x - rhs._x) + (lhs._y - rhs._y)* (lhs._y - rhs._y));
	}
void  Line::setPoint( Point & rhs, int x, int y)
	{
           rhs._x = x;
           rhs._y = y; 
	}


int main()
{
    Point point1(3,4);
	Point point2(0,0);
	Line line(3);
    
	point1.print();
	point2.print();
	line.setPoint(point2, 4, 4);
	point2.print();

  return 0;
}
