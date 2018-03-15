 ///
 /// @file    reverse.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-06 21:06:46
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int>VecInt{1, 2, 3, 4, 5};
    vector<int>::reverse_iterator New;

	for(New = VecInt.rbegin(); New != VecInt.rend(); ++New)
	{
       cout << *New << endl;
	}
    return 0;
}
