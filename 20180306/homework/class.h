 ///
 /// @file    class.h
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-02-28 17:43:21
 ///
#ifndef CLASS_H_
#define CLASS_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::fstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::map;
using std::unordered_map;
using std::string;
class WordStatistic
{
public:
	void init()
	{
      character.reserve(50);
	}
    void readFile(const string & filename)
	{
		ifstream ifs;
		ifs.open(filename);
		 while(getline(ifs, line))
		 { 
         	 character.push_back(line);   
		 }
		 for(auto & elem : character)
	     {
          stringstream ss(elem);
		while( !ss.eof())
			{
				ss >> word;
		   	  WordStatisticfunction(word);
			}
	   }
		ifs.close();
	}

	void writeFile(const std::string & filename)
	{
     ofstream ofs("result.txt");  
	 ofs.seekp(std::ios::beg);  
	
    for(auto &elem : element)
		{
           ofs  << elem.first << "  " << elem.second << endl;
		}
        ofs.close();
		cout << "end.\n";
	}

    void WordStatisticfunction(const string & s)
    {
        ++element[s];
  	}
private:
	vector<std::string>character;
	string line;
	string word;
	unordered_map<string, int>element;
	};
/* bool comp(const data &a, const data &b)
	{
        return a.num > b.num;
	}
*/
#endif
