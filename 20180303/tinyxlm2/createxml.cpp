 ///
 /// @file    setxml.cpp
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-11 15:56:01
 ///
 
#include <iostream>
#include "tinyxml2.h"
#include <string>
#include <stdlib.h>
using namespace std;
using namespace tinyxml2;
class User
{
public:
//	User(int _gender = 0) : gender(_gender) { }
	User(const string & userName, const string &password,/* int gender,*/ const string &mobile, const string &email)
	{
		this->userName = userName;
		this->password = password;
	//	this->gender = gender;
		this->mobile = mobile;
		this->email = email;
	}

	string userName;
	string password;
//	int gender;
	string mobile;
	string email;
};
int createXML(const char * xmlPath)
{
	const char * declaration = "<?xml veson=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
	XMLDocument doc;
	doc.Parse(declaration);

	XMLElement * root = doc.NewElement("DBUSER");
	doc.InsertEndChild(root);

	return doc.SaveFile(xmlPath);
};

int insertXMLNode(const char * xmlPath, const User &user)
{
	XMLDocument doc;
	int res = doc.LoadFile(xmlPath);
	if(res != 0)
	{
	    cout << "Load xml file failed" << endl;
		return res;
	}
	XMLElement* root = doc.RootElement();

	XMLElement * userNode = doc.NewElement("User");
    userNode->SetAttribute("Name", user.userName.c_str());
    userNode->SetAttribute("Password", user.password.c_str());
	root->InsertEndChild(userNode);

/*	XMLElement *gender = doc.NewElement("Gender");
	XMLText* genderText = doc.NewText(user.gender);
	gender->InsertEndChild(genderText);
	userNode->InsertEndChild(gender);
*/
	XMLElement *mobile = doc.NewElement("Mobile");
    mobile->InsertEndChild(doc.NewText(user.email.c_str()));
	userNode->InsertEndChild(mobile);
 
	XMLElement * email = doc.NewElement("Email");
	email->InsertEndChild(doc.NewText(user.email.c_str()));
	userNode->InsertEndChild(email);
	return doc.SaveFile(xmlPath);
}

void print(const char* xmlPath)
{
    XMLDocument doc;
	if(doc.LoadFile(xmlPath))
	{
	   cout << "Load xml file failed.\n";
	   return;
	}
	doc.Print();
}

int main()
{
   // createXML("/home/lee/20180303/tinyxlm2/t.xml");
   
   //	User user("kogan", "code","131","d32");
   //  insertXMLNode("/home/lee/20180303/tinyxlm2/t.xml", user);
    print("./rss/36kr.xml");
	return 0;
}
