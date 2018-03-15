 ///
 /// @file    Singleton.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-27 22:53:41
 ///
 
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class Singleton
{
public:
   static   Singleton *getInstance()    
	{
       if(NULL == _pInstance)
	   {
          _pInstance = new Singleton;
	   }
       return  _pInstance;
	}
private:
    Singleton()
	{
	};
    static Singleton * _pInstance;
};
Singleton *Singleton::_pInstance = NULL;

int main()
{
    Singleton * sing =  Singleton::getInstance();
 	cout << &sing << endl;

    return 0;
}
