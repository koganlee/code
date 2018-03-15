///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-23 15:55:00
 ///
 
#include <iostream>
#include <string>
#include <cstring>
class String
{
  private:
	 char * s;
  public:
	  String();
	  String(const char *ptr);
	  String(const String & rhs);
	  String & operator = (const String & rhs);
	  ~String();
	  void print();
};
int main()
{ 
    String str;
	str.print();
    String str2 = "Hello World";
	String str3("Hello");
	str2.print();
	str3.print();
    String str4 = str3;
	str4.print();
    return 0;
}

String::String()
{
   s = new char[5];
   std::strcpy(s, "none");
}


String::String(const char *pstr)
{
   int len =  std::strlen(pstr);
   s = new char[ len + 1];
   std::strcpy(s, pstr);
}

String::String(const String & rhs)
{
   int len =  std::strlen(rhs.s);
   s = new char[ len + 1];
   std::strcpy(s, rhs.s);
}

String & String::operator = (const String & rhs)
{
   int len =  std::strlen(rhs.s);
   s = new char[ len + 1];
   std::strcpy(s, rhs.s);
}

void String::print()
{
    std::cout << "s:" << s << std::endl;
}

String::~String()
{
   delete[] s;
}
