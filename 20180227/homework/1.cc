 ///
 /// @file    1.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-28 17:34:48
 ///
#include "class.h" 
#include <sstream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

int main()
{
    WordStatistic test;
    data base;
	test.init();
	test.readFile("The_Holy_Bible.txt");
	test.writeFile("test");

	return 0;
}
