 ///
 /// @file    map.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-12 17:42:47
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

int main()
{
   map<string, int> p{{"s",1}};
   ++p["s"];
   ++p["df"];
   for(auto &elem : p)
   cout << elem.first << elem.second << endl;
   
   return 0;
}
