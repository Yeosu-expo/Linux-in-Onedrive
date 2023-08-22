#include <iostream>
#include <string>
#include <list>
using namespace std;

class Mediator{
	public:
		virtual void receiveEvent(string event) = 0;
		virtual void sendEventToColleague(string event) = 0;
};

class Colleague{
	protected:
		string name;
		string event;
		Mediator *mediator;
	public:
		Colleague(string name){
			this->name = name;
		}
		void setMediator(Mediator *mediator){
			this->mediator = mediator;
		}
		void sendEvent(){
			mediator->receiveEvent(event);
		}
		void eventing(string event){
			this->event = event;
			sendEvent();
		}
		virtual void recieve(string present) = 0;
};

class ConcreteColleagueA:public Colleague{
	public:
		ConcreteColleagueA(string name):Colleague(name){}
		void recieve(string present){
			cout << name << "(ConcreteColleagueA)" << " recieve " << present << endl;
		}
};

class ConcreteColleagueB:public Colleague{
	public:
		ConcreteColleagueB(string name):Colleague(name){}
		void recieve(string present){
			cout << name << "(ConcreteColleagueB)" << " recieve " << present << endl;
		}
};

class ConcreteColleagueC:public Colleague{
	public:
		ConcreteColleagueC(string name):Colleague(name){}
		void recieve(string present){
			cout << name << "(ConcreteColleagueB)" << " recieve " << present << endl;
		}
};

class ConcreteMediator:public Mediator{
	private:
		string name;
		string event;
		list<Colleague*> colleagueList;
	public:
		ConcreteMediator(string nameValue):name(nameValue){}
		void addColleague(Colleague* colleague){
			colleagueList.push_back(colleague);
		}
		void sendEventToColleague(string event){
			list<Colleague*>::iterator iter;
			for(iter=colleagueList.begin();iter!=colleagueList.end();iter++)
				(*iter)->recieve(event);
		}
		void receiveEvent(string event){
			this->event = event;
			sendEventToColleague(event);
		}
};

void Client(){
	ConcreteMediator* mediator = new ConcreteMediator("mediator1");
	
	ConcreteColleagueA* colleagueA = new ConcreteColleagueA("colleagueA");
	ConcreteColleagueB* colleagueB = new ConcreteColleagueB("colleagueB");
	ConcreteColleagueC* colleagueC = new ConcreteColleagueC("colleagueC");

	colleagueA->setMediator(mediator);
	colleagueB->setMediator(mediator);
	colleagueC->setMediator(mediator);

	mediator->addColleague(colleagueA);
	mediator->addColleague(colleagueB);
	mediator->addColleague(colleagueC);

	colleagueA->eventing("event in colleagueA");
}

int main(){
	Client();

	return 0;
}
