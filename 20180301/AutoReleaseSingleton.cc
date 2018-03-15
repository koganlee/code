 ///
 /// @file    AutoReleaseSingleton.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-04 22:27:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Singleton
{
public:
    static Singleton *getInstance()
	{
       if(NULL == _pInstance)
	   {
          _pInstance = new Singleton;
       }
	   return _pInstance;
	}

	class AutoRelease
	{
		public:
			AutoRelease() { cout << "AutoRelease()" << endl;}

			~AutoRelease()
			{
			    if(_pInstance)
				{
					delete _pInstance;
				    cout << "~AutoRelease().\n";
				}
			}
	};
private:
	Singleton(){ }
	~Singleton() {}
	static Singleton * _auto;
	static  Singleton  *_pInstance;
};

//Singleton * Singleton::_pInstance = NULL;   //饿汉模式
//Singleton::AutoRelease Singleton::_auto;

Singleton * Singleton::_pInstance = getInstance(); //饱汉模式
int main()
{
  Singleton * ptr = Singleton::getInstance();

  cout << ptr << endl;

}
