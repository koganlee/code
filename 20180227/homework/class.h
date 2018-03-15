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
struct data{
	std::string s;
	int num;
};
 bool operator<(const data &a, const data &b)
{
    return a.num < b.num;
}
/*bool comp(const data &a, const data &b)
{
    return a.num < b.num;
} */

class WordStatistic
{
public:
	void init()
	{
      character.reserve(50);
	  element.reserve(50);
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
	
	 sort(element.begin(), element.end());
    	int num;
		for(num = 0; num < element.size(); num++)
		{
           ofs  << element[num].s << "  " << element[num].num << endl;
		}
        ofs.close();
		cout << "end.\n";
	}

    void WordStatisticfunction(const string & s)
    {
        size_t num;
    	for(num = 0; num < element.size(); num++)
    	{
          if( s == element[num].s)
	    	{
            ++element[num].num;
			break;
		    }
    	}
     	if(num >= element.size())
     	{
	    	data temp;
	    	temp.s = s;
	    	temp.num = 1;
            element.push_back(temp);
     	} 
	}
private:
	vector<std::string>character;
	string line;
	string word;
	vector<data>element;
	};
/* bool comp(const data &a, const data &b)
	{
        return a.num > b.num;
	}
*/
#endif
