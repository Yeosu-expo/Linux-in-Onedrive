#ifndef MUSICINFO_H
#define MUSICINFO_H

class MusicInfo:public Content{
		string genre;
	public:
		//MusicInfo();
		MusicInfo(string text=" ", string speaker=" ", string genre=" ") : Content(text, speaker);
		virtual string getText();
		virtual string getSpeaker();
		virtual string getGenre();
};

#endif
