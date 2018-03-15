 ///
 /// @file    set.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-08 22:33:45
 ///
 
#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
//using std::set;
using std::multiset;
int main()
{
    multiset<int> setInt{1, 9, 3, 5, 3, 5, 8, 9};
    multiset<int>::const_iterator cit;
    
	for(cit = setInt.begin(); cit != setInt.end(); ++cit)
	{
       cout << *cit << endl;
	}
    return 0;
}
