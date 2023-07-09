#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MediaInfo{
	public:
		string title;
		virtual string GetTitle();
		MediaInfo(string title);
};

MediaInfo::MediaInfo(string title=" ") { this->title=title; }
string MediaInfo::GetTitle() { return "Media "+title; }

class AudioInfo:public MediaInfo{
	public:
		virtual string GetTitle();
		AudioInfo(string title);
};

AudioInfo::AudioInfo(string title=" ") { this->title=title; }
string AudioInfo::GetTitle(){ return "Audio "+title; }

class VideoInfo:public MediaInfo{
	public:
		virtual string GetTitle();
		VideoInfo(string title);
};

VideoInfo::VideoInfo(string title=" ") { this->title=title; }
string VideoInfo::GetTitle() { return "Video "+title; }

class RadioInfo:public MediaInfo{
	public:
		virtual string GetTitle();
		RadioInfo(string title);
};

RadioInfo::RadioInfo(string title=" ") { this->title=title; }
string RadioInfo::GetTitle() { return "Radio "+title; }

void printMediaInfoVec(vector<MediaInfo*>& mediaInfoVec){
	for(int i=0;i<mediaInfoVec.size();i++)
		cout << mediaInfoVec[i]->GetTitle() << endl;
	cout << endl;
}

int main(){

	//vector<VideoInfo*> videoInfoVec;
	//vector<RadioInfo*> radioInfoVec;
	//vector<AudioInfo*> audioInfoVec;
	
	vector<MediaInfo*> mediaInfoVec;

	mediaInfoVec.push_back(new VideoInfo("Video 1"));
	mediaInfoVec.push_back(new VideoInfo("Video 2"));
	mediaInfoVec.push_back(new RadioInfo("Radio 1"));
	mediaInfoVec.push_back(new RadioInfo("Radio 2"));
	mediaInfoVec.push_back(new AudioInfo("Audio 1"));
	mediaInfoVec.push_back(new AudioInfo("Audio 2"));

	printMediaInfoVec(mediaInfoVec);
}
