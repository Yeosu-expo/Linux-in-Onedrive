#include "content.h"
#ifndef VIDEOINFO_H
#define VIDEOINFO_H
using namespace std;

class VideoInfo:public Content{
		string genre;
	public:
		VideoInfo();
		VideoInfo(string text, string title, string genre);
		virtual string getValue();
};
#endif 
