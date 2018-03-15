 ///
 /// @file    lvalueRvalue.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-12 09:22:54
 ///
 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int && func()
{
	return 10;
}

int main(void)
{
	int a = 1;
	int b = 2;
	int *pFlag = &a;
	vector<int> vec;
	vec.push_back(1);

	string s1 = "Hello";
	string s2 = "world";

	const int & m = 1;
	const int & n = a;

	int &&y = 1;

	func();
    return 0;
}
