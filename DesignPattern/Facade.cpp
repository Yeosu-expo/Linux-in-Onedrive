#include <iostream>
#include <string>
using namespace std;

class PCRoom{
	public:
		~PCRoom() { cout << "get out of PCRoom" << endl; }
		void enterPCRoom() { cout << "enter PCRoom" << endl; }
};

class Computer{
	public:
		~Computer() { cout << "Turn off the Computer" << endl; }
		void turnOn() { cout << "Turn on the Computer" << endl; }
};

class GameProgram{
	string ID;
	public:
		~GameProgram() { cout << ID << " logout" << endl; }
		void login(string ID) {
			this->ID =  ID;
			cout << ID << " login" << endl;	
		}
		void gaming(){
			cout << ID << " is gaming" << endl;	
		}
};

class Facade{
	PCRoom *pcroom;
	Computer *computer;
	GameProgram *gameProgram;
	
	public:
		Facade(){
			pcroom = new PCRoom();
			computer = new Computer();
			gameProgram = new GameProgram();	
		}
		~Facade(){
			cout << endl;
			delete(gameProgram);
			delete(computer);
			delete(pcroom);	
		}
		void DoGame(string ID){
			pcroom->enterPCRoom();
			computer->turnOn();
			gameProgram->login(ID);
			gameProgram->gaming();	
		}
};

void Client(){
	Facade *facade = new Facade();
	facade->DoGame("아무개");

	delete(facade);
}

int main(){
	Client();

	return 0;
}
