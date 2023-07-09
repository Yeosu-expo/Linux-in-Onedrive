#ifndef QUIZ_H
#define QUIZ_H
#include "content.h"
#include "videoInfo.h"
#include <vector>
#include <string>
class Quiz{
		vector<Content*> contentVec;
		int randomNum;
		string answer;
	public:
		Quiz();
		virtual void play();
		void printQuiz(string text);
		void getAnswer();	
		void compareAnswer(string title);
		string getClassName(Content* c);
};
#endif
