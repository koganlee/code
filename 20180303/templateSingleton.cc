 ///
 /// @file    templateSingleton.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-09 22:01:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Point
{
public:
	Point(int x = 0, int y = 0) : _x(x), _y(y){ }
	void print();
    friend ostream &operator<<(ostream &os, const Point & p);
private:
    int _x;
	int _y;
};

void Point::print()
{
   cout << "(" << _x <<
	       "," << _y << 
		   ").\n";
}

ostream &operator<<(ostream &os, const Point & p)
{
    os  << "(" << p._x <<
	       "," << p._y << 
		   ").";
}

template<typename T>
class Singleton
{
public:
	class AutoRelease
	{
      public:
		  AutoRelease() {}
		  ~AutoRelease() {
			  if(_pstr)
				  delete _pstr;
		  }

	};
    
	static T *getInstance();
/*
	void destroy()
	{
		if(_pstr)
		{
			delete _pstr;
		}
	}
	*/
private:
	static T * _pstr;
	static AutoRelease _autoRelease;
    Singleton(){ }
	~Singleton() { };
};
template<typename T>
T * Singleton<T>::_pstr = NULL;

template<typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;

template <typename T>
T * Singleton<T>::getInstance()
	{
		if(_pstr == NULL)
		{
           _pstr = new T;
		}
        return _pstr;
	}

int main()
{
    Point * ptr= Singleton<Point>::getInstance();

    ptr -> print(); 
	cout << &ptr << endl;

}
