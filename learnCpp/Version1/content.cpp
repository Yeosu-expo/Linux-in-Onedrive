#include "content.h"
#include <string>
#include <utility>
using namespace std;

Content::Content(string text=" ", string title=" "){
	this->text=text;
	this->title=title;
}

string Content::getText(){
	return text;
}

string Content::getValue(){
	return NULL;
}

string Content::getTitle(){
	return title;
}
