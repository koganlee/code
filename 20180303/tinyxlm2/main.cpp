 ///
 /// @file    main.cpp
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-11 12:03:42
 ///
 
#include <iostream>
#include "tinyxml2.h"
#include <stdio.h>
#include <string>
using std::cout;
using std::endl;
using namespace std;
using namespace tinyxml2;

#if 1
void example1()
{
	XMLDocument doc;
	doc.LoadFile("test.xml");
	const char *content = doc.FirstChildElement("Hello")->GetText();
	printf("Hello,%s", content);
}
#endif

int example_1()
{
	XMLDocument doc;
    doc.LoadFile("text.xml");
	doc.Parse("test.xml");
	return doc.ErrorID();
}

int example_2()
{
	static const char* xml = "<element/>";
	XMLDocument doc;
	doc.Parse(xml);

	return doc.ErrorID();
}

int example_3()
{
	static const char *xml = 
		"<?xml version = \"1.0\"?>"
		"<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
		"<PLAY>"
		"<TITLE>A Midsummer Night's Dream</TITLE>"
		"</PLAY>";

	XMLDocument doc;
	doc.Parse(xml);

    XMLElement* titleElement = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE");
	const char *title = titleElement->GetText();
	printf("Name of play(1):%s\n", title);

	XMLText* textNode = titleElement->FirstChild()->ToText();
	title = textNode->Value();
	printf("Name of play (2): %s\n", title);

	return doc.ErrorID();
}

int example_4()
{
   static const char* xml = 
	   "<information>"
	   "    <attributeApproach v='2' />"
	   "    <textApproach>"
	   "        <v>2</v>"
	   "    </textApproach>"
	   "</information>";

   XMLDocument doc;
   doc.Parse(xml);
   
   int v0 = 0;
   int v1 = 0;
  
   XMLElement* attributeApproachElement = doc.FirstChildElement()->FirstChildElement("attributeApproach");
   attributeApproachElement->QueryIntAttribute("v", &v0);

   XMLElement* textApproachElement = doc.FirstChildElement()->FirstChildElement("textApproach");
   textApproachElement->FirstChildElement("v")->QueryIntText(&v1);
   printf("Both values are the same :%d and %d\n", v0, v1);

   return !doc.Error() && (v0 == v1);
}



#if 0
void example2()
{
  XMLDocument doc;
  doc.LoadFile("./rss/36kr.xml");
  XMLElement *title = doc.RootElement();
  XMLElement *surface = title -> FirstChildElement("title");
  while(surface)
  {
	  XMLElement * surfaceChild = surface->FirstChildElement();
	  const char *content;
	  const XMLAttribute *attributeOfSurface = surface->FirstAttribute();
	  cout << attributeOfSurface->Name() << ":" << attributeOfSurface->Value() << endl;
	  while(surfaceChild)
	  {
		  content = surfaceChild->GetText();
		  surfaceChild = surfaceChild->NextSiblingElement();
		  cout << content << endl;
	  }
      surface = surface->NextSiblingElement();
  }
}
#endif

int main()
{
   //int res = example_1();
   XMLDocument doc;
   doc.LoadFile("./rss/coolshell.xml");
   XMLElement* titleElement = doc.FirstChildElement(/*"channel"*/)->FirstChildElement("channel")->FirstChildElement("title");

   string title;
	title = titleElement->GetText();
   printf("%s\n", title.c_str());

  // doc.ErrorID();
   return 0;
}
