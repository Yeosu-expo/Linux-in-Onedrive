#include <iostream>
#include <string>
using namespace std;

class SingInfo{
	private:
		string song;
		string elvis;
		string singer;
	public:
		SingInfo(string songg, string elviss);
		void quiz();
		void printQuestion();
		void getSinger();
		void compareAnswer(string singerr);
};

SingInfo::SingInfo(string songg, string elviss){
	song=songg, elvis=elviss;
}

void SingInfo::quiz(){
	printQuestion();
	getSinger();
	compareAnswer(singer);
}
void SingInfo::printQuestion(){
 	cout << song+"를 부른 가수는";
	cout << "(힌트: 첫글자는 " << elvis[0] << ")?";
}

void SingInfo::getSinger(){
	getline(cin, singer);
}

void SingInfo::compareAnswer(string singerr){
	if(singerr==elvis)
		cout << "맞았습니다." << endl;
	else
		cout << "틀렸습니다." + elvis + "입니다." << endl;	
}

int main(){
	SingInfo singInfo("Falling in love with you", "Elvis Presley");

	singInfo.quiz();
	return 0;
}
