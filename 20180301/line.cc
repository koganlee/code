 ///
 /// @file    line.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-01 16:00:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Line::Impl
{
	class Point
	{
      public:
        Point(int x, int y) : _x(x), _y(y)
		{
            cout << "Point().\n";
		}

		void print() const
		{
           cout << "(" << _x << "," 
			    << _y << ").\n";
		}
	  private::
		 int _x;
		 int _y;

	};
};

int main()
{
  Line line(4, 5, 6, 7);
  line.printLine();

  return 0;
}
