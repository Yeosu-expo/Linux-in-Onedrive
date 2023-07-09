#include "audioInfo.h"
#include <utility>
#include <string>
using namespace std;

AudioInfo::AudioInfo(string text=" ", string title=" ", string album=" "): Content(text, title){
	this->album = album;
}

pair<pair<string, string>, string> AudioInfo::getInfo(){
	pair<pair<string, string>, string> tmp;
	pair<string, string> contentTmp;
	contentTmp=getInfo();
	tmp.first=make_pair(contentTmp);
	tmp.second=album;

	return tmp;
}
