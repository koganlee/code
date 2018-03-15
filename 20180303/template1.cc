 ///
 /// @file    template1.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-07 15:55:11
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

template <class T>
T add(T x, T y)
{
    cout << "T add(T, T)" << endl;
	return x + y;
}

template <class T>
T add(T x, T y, T z)
{
	return x + y + z;
}

template<>
char * add<char *>(char * s1, char * s2)
{
    char * temp = new char[strlen(s1) + strlen(s2) + 1];
	strcpy(temp, s1);
	strcat(temp, s2);
    return temp;
}
int add(int x, int y)
{
    cout << "int add(int, int)" << endl;
	return x + y;
}

int main()
{
    char s1[] = "Hello";
	char s2[] = "World";

	cout << add(s1, s2) << endl;
	return 0;
}
