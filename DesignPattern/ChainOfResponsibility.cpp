#include <iostream>
#include <string>
using namespace std;

enum Request{
	CASE_A,
	CASE_B,
	CASE_C,
};

class Handler{
	protected:
		Handler* nextHandler;
	public:
		void setNextHandler(Handler* handler){
			this->nextHandler = handler;
		}
		virtual void handleRequest(Request request) = 0;
};

class ConcreteHandlerA:public Handler{
	public:
	void handleRequest(Request request){
		if(request == CASE_A){
			cout << "CASE_A completed\n" << endl;
		}
		else{
			cout << "CASE_A Failed" << endl;
			nextHandler->handleRequest(request);
		}
	}
};

class ConcreteHandlerB:public Handler{
	public:
	void handleRequest(Request request){
		if(request == CASE_B){
			cout << "CASE_B completed\n" << endl;
		}
		else{
			cout << "CASE_B Failed" << endl;
			nextHandler->handleRequest(request);
		}
	}
};

class ConcreteHandlerC:public Handler{
	public:
	void handleRequest(Request request){
		if(request == CASE_C){
			cout << "CASE_C completed\n" << endl;
		}
		else{
			cout << "CASE_C Failed" << endl;
			nextHandler->handleRequest(request);
		}
	}
};

void Client(){
	Request request[3] = {CASE_A, CASE_B, CASE_C};

	ConcreteHandlerA *caseA = new ConcreteHandlerA();
	ConcreteHandlerB *caseB = new ConcreteHandlerB();
	ConcreteHandlerC *caseC = new ConcreteHandlerC();
	caseA->setNextHandler(caseB);
	caseB->setNextHandler(caseC);

	caseA->handleRequest(request[0]);
	caseA->handleRequest(request[1]);
	caseA->handleRequest(request[2]);
}

int main(){
	Client();

	return 0;
}
