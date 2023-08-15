#include <iostream>
#include <string>
using namespace std;

class Strategy{
	public:
		virtual void printSelf() = 0;
};

class ConcreteStrategyA:public Strategy{
	public:
		void printSelf() { cout << "Here is A" << endl; }
};

class ConcreteStrategyB:public Strategy{
	public:
		void printSelf() { cout << "Here is B" << endl; }
};

class ConcreteStrategyC:public Strategy{
	public:
		void printSelf() { cout << "Here is C" << endl; }
};

void printFunc(Strategy *strategy){
	strategy->printSelf();
}

void Client(){
	printFunc(new ConcreteStrategyA());
	printFunc(new ConcreteStrategyB());
	printFunc(new ConcreteStrategyC());
}

int main(){
	Client();

	return 0;
}
