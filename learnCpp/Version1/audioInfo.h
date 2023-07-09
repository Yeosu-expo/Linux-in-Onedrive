#ifndef AUDIOINFO_H
#define AUDIOINFO_H
#include "content.h"
#include <utility>
#include <string>
using namespace std;

class AudioInfo:public Content{
		string album;
	public:
		AudioInfo(string text, string title, string album): Content(text, title);
		virtual pair<pair<string, string>, string> getInfo();
}
#endif
