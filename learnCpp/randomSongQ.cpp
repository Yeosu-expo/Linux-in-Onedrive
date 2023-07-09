#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class SongInfo{
	private:
		string lyric;
		string singer;
	public:
		SongInfo();
		SongInfo(string lyricc, string singerr);
		void printQuestion();
		string giveSingerValue();
};

SongInfo::SongInfo(string lyricc, string singerr){
	lyric=lyricc;
	singer=singerr;
}

void SongInfo::printQuestion(){
	cout << lyric + "를 부른 가수는";
	cout << "(힌트 : 첫글자는 " << singer[0] << ")?";
}

string SongInfo::giveSingerValue(){
	return singer;
}

class Question{
	private:
		SongInfo *songInfo[5];
		string answer;
		int randomNum;
	public:
		Question();
		void quiz();
		void printQuestion();
		void getAnswer();
		void checkAnswer();
};

Question::Question(){
	long long tmp  = time(NULL)%5;
	randomNum=tmp;

	songInfo[0]= new SongInfo("A-B-C-D-E, F-U", "Gayle");
	songInfo[1]= new SongInfo("I'm in love with your body", "Ed Sheeran");
	songInfo[2]= new SongInfo("I do the same thing I told you that I never would", "The Kid LAROI");
	songInfo[3]= new SongInfo("Hello from the other side", "Adele");
	songInfo[4]= new SongInfo("I got my peaches out in Georgia (Oh yeah, shit)", "Justin Bieber");
} 

void Question::quiz(){
	printQuestion();
	getAnswer();
	checkAnswer();
}

void Question::printQuestion(){
	songInfo[randomNum]->printQuestion();
}

void Question::getAnswer(){
	getline(cin, answer);
}

void Question::checkAnswer(){
	string singer = songInfo[randomNum]->giveSingerValue();
	if(answer == singer)
		cout << "맞았습니다." << endl;
	else
		cout << "틀렸습니다. " + singer + "입니다." << endl;
}

int main(int argc, char* argv[]){
	Question q;
	q.quiz();

	return 0;
}
