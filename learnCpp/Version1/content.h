#ifndef CONTENT_H
#define CONTENT_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Content{
		string text;
		string title;
	public:
		Content();
		Content(string text, string title);
		string getText();
		string getTitle();
		virtual string getValue();
};

#endif
