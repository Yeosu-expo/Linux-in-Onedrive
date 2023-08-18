#include <iostream>
#include <string>
#include <list>
using namespace std;

class Observer{
	public:
		virtual void update() = 0;
};

class ConcreteObserverA:public Observer{
	public:
		void update() { cout << "ObserverA Update" << endl; }
};

class ConcreteObserverB:public Observer{
	public:
		void update() { cout << "ObserverB Update" << endl; }
};

class Object{
	protected:
		list<Observer*> observerList;
	public:
		void attach(Observer* observer){
			observerList.push_back(observer);
		}
		void detach(Observer* observer){
			observerList.remove(observer);
		}
		void notify(){
			list<Observer*>::iterator iter;
			for(iter=observerList.begin();iter!=observerList.end();iter++){
				(*iter)->update();
			}
		}
};

class ConcreteObjectA:public Object{
	public:
		void eventA(){
			cout << "EventA occur int ConcreteObjectA" << endl;
			notify();
		}
		void eventB(){
			cout << "EventB occur int ConcreteObjectA" << endl;
			notify();
		}
};

void Client(){
	ConcreteObjectA* obj =  new ConcreteObjectA();
	ConcreteObserverA* observerA = new ConcreteObserverA();
	ConcreteObserverB* observerB = new ConcreteObserverB();

	obj->attach(observerA);
	obj->attach(observerB);
	obj->eventA();

	obj->detach(observerA);
	obj->eventB();

	delete(observerA);
	delete(observerB);
	delete(obj);
}

int main(){
	Client();

	return 0;
}
