 ///
 /// @file    AutoReleaseSingleton.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-04 22:27:36
 ///
 
#include <iostream>
#include <cstdlib>
#include <pthread.h>
using std::cout;
using std::endl;
class Singleton
{
public:
    static Singleton *getInstance()
	{
      ::pthread_once(&_once, init);
	  return _pInstance;
	}
	
	static void init(void)
    {
		_pInstance = new Singleton;
		::atexit(destory);
	}
    static void destory(void)
	{
        if(_pInstance)
		    delete _pInstance;
	}
 
private:
	Singleton(){ }
	~Singleton() {}
	static pthread_once_t _once;
	static  Singleton  *_pInstance;
};

Singleton * Singleton::_pInstance = NULL;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;
int main()
{
  Singleton * ptr = Singleton::getInstance();

  cout << ptr << endl;

}
