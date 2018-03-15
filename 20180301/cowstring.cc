 ///
 /// @file    cowstring.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-05 14:30:34
 ///
 
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
class String
{

	class CharProxy
	{
      public: 
		  CharProxy(String & self, size_t idx):_self(self), _idx(idx) {}
          CharProxy & operator = (const char &ch);
    
		  friend std::ostream &operator << (std::ostream &os, const CharProxy & rhs);
	  private:
		  String &_self;
		  size_t _idx;
	};
	friend std::ostream & operator << (std::ostream & os, const CharProxy & rhs);
public:
   String();
   String(const char * pstr);
   String(const String & rhs);
   String & operator=(const String & rhs);
   ~String();

   CharProxy  operator[](size_t idx);

   int refcount()
   {
	   return *(int *)(_pstr - 4);
   }

   const char *c_str() const
   {
	   return _pstr;
   }
   
   size_t size() const 
   { 
	   return strlen(_pstr);
   }
private:
    void InitRefCount()
	{
       *(int *)(_pstr - 4) = 1;
	}

	void AddRefCount()
	{
     ++(*(int *)(_pstr - 4));
	}

    void SubRefCount()
	{
     --(*(int *)(_pstr - 4));
	}

	void release()
	{
		SubRefCount();
		if(refcount() == 0)
		{
			delete[] (_pstr - 4);
			cout << "~String()" << endl;
		}
	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
	char * _pstr;
};


String::String() : _pstr(new char[5]() + 4)
{
    InitRefCount();  
}

String::String(const char *pstr) : _pstr(new char [strlen(pstr) + 5]() + 4)
{
   strcpy(_pstr, pstr);
   InitRefCount();
 }

String::String(const String &rhs) : _pstr(rhs._pstr)
{
    AddRefCount(); 
}

String::~String()
{
    release();
}

String & String::operator=(const String & rhs)
{
    if(this != &rhs)
	{
		release();
		_pstr = rhs._pstr;
		InitRefCount();
	}
	return *this;
}

String::CharProxy  String::operator[](size_t idx)
{
	return CharProxy(*this, idx);
}

std::ostream & operator << (std::ostream & os,const String &rhs)
{
    os << rhs._pstr;
	return os;
}
std::ostream & operator << (std::ostream & os,const String::CharProxy &rhs)
{
    os << rhs._self._pstr[rhs._idx];
	return os;
}
String::CharProxy & String::CharProxy::operator=(const char &ch)
{
	if(_idx < _self.size())
	{
		if(_self.refcount() > 1)
		{
		   _self.SubRefCount();
		   char * ptmp = new char[_self.size() + 5]() + 4;
		   strcpy(ptmp, _self._pstr);
		   _self._pstr = ptmp;
           _self.InitRefCount();
		}
		_self._pstr[_idx] = ch;
	}
}

int main()
{
   String s1 = "abcd";
   String s2(s1);
   String s3(s1); // = "possible";
   
   cout << "s1: " << s1.refcount() << endl;
   cout << "s2: " << s2.refcount() << endl;
   cout << "s3: " << s3.refcount() << endl;
   cout << "read.\n";
   cout << s3[2];
   
   return 0;
}
