 ///
 /// @file    iterator.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-06 17:26:49
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;
void function()
{
  vector<int>VecInt{1, 2, 3, 4, 5};
  ostream_iterator<int> osi(cout, "-");
  copy(VecInt.begin(), VecInt.end(), osi);
  cout << endl;
}

void function2()
{
  vector<int>VecInt;
  istream_iterator<int> isi(cin);
  copy(isi, istream_iterator<int>(), back_inserter(VecInt));
  ostream_iterator<int> osi(cout, "-");
  copy(VecInt.begin(), VecInt.end(), osi);
  
  cout << endl;
/*  for(auto &elem : VecInt)
  {
	  cout << elem << endl;
  }
*/
 // copy(VecInt.begin(), VecInt.end(), osi);
 }
int main()
{
  function2();	
	
  return 0;
}
