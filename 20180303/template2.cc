 ///
 /// @file    template2.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-07 15:59:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;
template < typename T, int number>
T func(T x, T y)
{
	return x * y * number;
}

int main()
{
    int a = 1;
	int b = 2;

    cout << func<int, 30>(a, b) << endl;
    return 0;
}
