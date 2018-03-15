 ///
 /// @file    vector.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-02 09:37:11
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
struct data
{
	string s;
	int num;
}temp;
int main()
{
   vector<data>element;
   element.reserve(10);
   temp.s="fd";
   temp.num = 1;
   element.push_back(temp);
   temp.s = "ha";
   temp.num = 3;
   element.push_back(temp);
   
   size_t num = 0;
   for( ; num < element.size(); num++)
   {
      cout << element[num].s  << " " << element[num].num << endl;
   }
   return 0;
}
