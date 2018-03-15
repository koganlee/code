 ///
 /// @file    Point.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-02 15:46:41
 ///
 
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
class Point;
class Line
{
public:
	void  distance(const Point &p1, const Point &p2);
};

class Point
{

public:	  
     Point(int x = 0, int y = 0):_x(x), _y(y)
	  {
		  cout << "Initalize1.\n";
	  }

	  void   print() const
	  {
         cout << "x=" << _x  << ",y =" << _y << endl;

	  }
	   friend void Line::distance(const Point &p1, const Point &p2);
private:
	int _x;
	int _y;
};
    void Line::distance(const Point &p1, const Point &p2)
    {
        cout << "distance: " << sqrt((p1._x - p2._x)*(p1._x - p2._x)+(p1._y -  p2._y) * (p1._y - p2._y))
                             << endl;
	} 


int main(void)
{
     Point point(3,4);
	 Point point1;
	 point.print();
	 point1.print();
     Line line;
	 line.distance(point, point1);
     return 0;
}
