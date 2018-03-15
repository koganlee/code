 ///
 /// @file    vector.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-28 14:37:42
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
   vector<int> numbers;
   numbers.reserve(10);
   
   numbers.push_back(3);
   cout << numbers.front() << endl;
   cout << numbers.back() << endl;
   numbers.push_back(10);
   cout << numbers.front() << endl;
   cout << numbers.back() << endl;


  return 0;
}
