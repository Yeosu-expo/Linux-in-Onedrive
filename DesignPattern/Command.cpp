#include <iostream>
#include <string>
using namespace std;

class Command{
	public:
		virtual void execute() = 0;
};

class Button{
	Command *command;
	public:
		void setCommand(Command* command){
			this->command = command;		
		}
		void press(){
			command->execute();
		}
};

class Missile{
	public:
		void launch(){
			cout << "Missile fired" << endl;
		}
};

class Radio{
	public:
		void play(){
			cout << "Radio play" << endl;
		}
};

class RadioCommand:public Command{
	Radio* radio;
	public:
		RadioCommand(Radio* radio){
			this->radio=radio;
		}
		void execute(){
			radio->play();
		}
};

class MissileCommand:public Command{
	Missile* missile;
	public:
		MissileCommand(Missile* missile){
			this->missile = missile;
		}
		void execute(){
			missile->launch();
		}
};

void Client(){
	Radio *radio = new Radio();
	RadioCommand* RC = new RadioCommand(radio);
	Missile* missile = new Missile();
	MissileCommand* MS = new MissileCommand(missile);

	Button button;
	button.setCommand(RC);
	button.press();

	button.setCommand(MS);
	button.press();
}

int main(){
	Client();

	return 0;
}
