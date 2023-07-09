#include <iostream>
#include <string>
#include "content.h"
using namespace std;

Content::Content(string text=" ", string speaker=" "){
	this->text=text;
	this->speaker=speaker;
}

virtual string getText(){
	return this->text;
}

virtual string getSpeaker(){
	return this->speaker;
}
