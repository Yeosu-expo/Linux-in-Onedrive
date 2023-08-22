#include <iostream>
#include <string>
using namespace std;

class AbstractClass{
	public:
		virtual void concreteMethod1() = 0;
		virtual void concreteMethod2() = 0;
		void method(){
			concreteMethod1();
			concreteMethod2();
		}
};

class SubClassA:public AbstractClass{
	public:
		void concreteMethod1(){
			cout << "ConcreteMethod1 in SubA" << endl;
		}
		void concreteMethod2(){
			cout << "ConcreteMethod2 in SubA" << endl;
		}
};

class SubClassB:public AbstractClass{
	public:
		void concreteMethod1(){
			cout << "ConcreteMethod1 in SubB" << endl;
		}
		void concreteMethod2(){
			cout << "ConcreteMethod2 in SubB" << endl;
		}
};

void Client(){
	SubClassA subA;
	subA.method();

	cout << endl;

	SubClassB subB;
	subB.method();
}

int main(){
	Client();

	return 0;
}
