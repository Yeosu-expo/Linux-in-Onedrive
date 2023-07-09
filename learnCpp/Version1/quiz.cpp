#include "quiz.h"
#include "videoInfo.h"
//#include "audioInfo.h"
#include <time.h>
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

Quiz::Quiz(){
	contentVec.push_back(new VideoInfo("김사장이 보냈소", "황해", "스릴러"));
	contentVec.push_back(new VideoInfo("쏠수있어!", "타짜", "범죄"));
	contentVec.push_back(new VideoInfo("예림이 그패봐봐", "타짜", "스릴러"));	

	long long rand=time(NULL)%contentVec.size();
	randomNum=(int)rand;
}

void Quiz::play(){
	string text=contentVec[randomNum]->getText();
	printQuiz(text);
	getAnswer();
	string title=contentVec[randomNum]->getTitle();
	compareAnswer(title);
}

void Quiz::printQuiz(string text){
	cout << "text: " << text << endl;
}

void Quiz::getAnswer(){
	cout << "What's title? " ;
	cin >> answer;
}

void Quiz::compareAnswer(string title){
	if(title==answer){
		cout << "Perfect!" << endl;
		return;	
	}
	cout << "Noob..." << endl;
}

string Quiz::getClassName(Content* c){
	return typeid(c).name();
}

