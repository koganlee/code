 ///
 /// @file    file.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-28 12:19:06
 ///
 
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

using std::string;
using std::ifstream;
using std::ostream;
using std::fstream;

int main()
{
   ifstream ifs;
   ifs.open("test.txt");
   if(!ifs)
   {
	   cout << "can't open this file" << endl;
	   return -1;
   }
   
   string line;
   
   while( getline(ifs,line))
   {
      cout << line << endl;
   }
 /*  while(getline(ifs, line))
   {

   }
 */
     return 0;
}
