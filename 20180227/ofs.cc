 ///
 /// @file    ofstream.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-28 15:15:32
 ///
 
#include <iostream>
#include <fstream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
int main()
{
    ofstream ofs;
	ofs.open("file.cc");

	if(!ofs.good())
	{
		cout << "Cant' open.\n";
		return -1;
	}

	vector<string> lines;
    lines.reserve(50);

	for(auto &elem : lines)
	{
        ofs << elem << endl;
	}

    return 0;
}
