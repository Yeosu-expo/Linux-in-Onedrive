#ifndef CONTENT_H
#define CONTENT_H

class Content{
		string text;
		string speaker;
	public:
		//Content();
		Content(string text=" ", string speaker=" ");
		virtual string getText();
		virtual string getSpeaker();
};

#endif
