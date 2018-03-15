 ///
 /// @file    line.h
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-01 16:02:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Line
{
public:
	   Line(int ,int , int, int);
	   ~Line();
       void printLine() const;
private:
   class Impl;
   Impl  *_pImpl; 
}
