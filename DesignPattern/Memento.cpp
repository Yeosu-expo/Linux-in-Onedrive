#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Memento{
	private:
		string info;
	public:
		Memento(string info_):info(info_){}
		string getInfo(){ return info; }
		void printInfo(){
			cout << "Memento Info:" << info << endl;
		}
};

class Originator{
	private:
		string info;
	public:
		Originator(string info_):info(info_){}
		void setInfo(string info){
			this->info=info;
		}
		void printInfo(){
			cout << "Originator Info:" << info << endl;
		}
		Memento* makeAndGetMemento(){
			return new Memento(info);
		}
};

class CareTaker{
	private:
		list<Memento*> mementoList;
	public:
		void appendMemento(Memento* memento){
			mementoList.push_back(memento);
		}
		Memento* getMemento(Memento* target){
			list<Memento*>::iterator iter;
			iter = find(mementoList.begin(), mementoList.end(), target);
			return *iter;
		}
};

void Client(){
	Originator* originator = new Originator("CASE A");
	CareTaker careTaker;

	Memento* memento1 = originator->makeAndGetMemento();
	originator->setInfo("CASE B");
	Memento* memento2 = originator->makeAndGetMemento();
	originator->setInfo("CASE C");
	Memento* memento3 = originator->makeAndGetMemento();

	careTaker.appendMemento(memento1);
	careTaker.appendMemento(memento2);
	careTaker.appendMemento(memento3);

	originator->printInfo();
	Memento* tmp;
	tmp = careTaker.getMemento(memento1);
	tmp->printInfo();
	tmp = careTaker.getMemento(memento2);
	tmp->printInfo();
	tmp = careTaker.getMemento(memento3);
	tmp->printInfo();
}

int main(){
	Client();

	return 0;
}
