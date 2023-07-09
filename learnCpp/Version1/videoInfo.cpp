#include "videoInfo.h"
using namespace std;

VideoInfo::VideoInfo(string text=" ", string title=" ", string genre=" "):Content(text, title){
	this->genre=genre;
}

string VideoInfo::getValue(){
	return genre;
}
