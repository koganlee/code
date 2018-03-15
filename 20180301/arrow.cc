 ///
 /// @file    arrow.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-04 16:28:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Data
{
public:
    int length()
	{
       return 5;
	}
};

class Dataptr
{
public:
   Dataptr() : _ptr(new Data)
	{
       cout << "Initial.\n";
	}
   ~Dataptr()
   {
	  cout << "delete Dataptr.\n";
      delete _ptr;
   }
   Data * operator ->()
   {
       return _ptr;
   }

   Data & operator *()
   {
        return * _ptr;
   }
private:
   Data *_ptr;
};


class ThirdLayer
{
public:
     ThirdLayer() : _ptr(new Dataptr)
	{
      cout << " ThirdLayer initialed.\n";
	}

	~ThirdLayer()
	{
	  cout << "dete ThirdLayer.\n";
      delete _ptr;
	} 
    
	Dataptr  & operator->()
	{
       return *_ptr;
	}

private:
	Dataptr * _ptr;
};

int main()
{
    Dataptr dp;
    cout << dp -> length() << endl;
	cout << dp.operator->() -> length() << endl;

	cout << (*dp).length() << endl;

	ThirdLayer ti;
	cout << ti -> length() << endl;
	cout << ti.operator -> ().operator -> () -> length() << endl; 
	return 0;
}
