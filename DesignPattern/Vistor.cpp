#include <iostream>
#include <string>
using namespace std;

class Vistor{
	public:
		virtual void visit(class ConcreteElementA* concreteElementA) = 0;
		virtual void visit(class ConcreteElementB* concreteElementB) = 0;
};

class Element{
	public:
		virtual void accept(Vistor* visitor) = 0;
};

class ConcreteElementA:public Element{
	public:
		string value;
		ConcreteElementA(string value){
			this->value = value;
		}
		void accept(Vistor* visitor){
			visitor->visit(this);
		}
};

class ConcreteElementB:public Element{
	public:
		string value;
		ConcreteElementB(string value){
			this->value = value;
		}
		void accept(Vistor* visitor){
			visitor->visit(this);
		}
};

class ConcreteVistor1:public Vistor{
	public:
		void visit(ConcreteElementA* concreteElementA){ 
			cout << "ElementA visit ConcreteVistor1: " << concreteElementA->value << endl; 
		}
		void visit(ConcreteElementB* concreteElementB){ 
			cout << "ElementB visit ConcreteVistor1: " << concreteElementB->value << endl; 
		}
};

class ConcreteVistor2:public Vistor{
	public:
		void visit(ConcreteElementA* concreteElementA){ 
			cout << "ElementA visit ConcreteVistor2: " << concreteElementA->value << endl; 
		}
		void visit(ConcreteElementB* concreteElementB){ 
			cout << "ElementB visit ConcreteVistor2: " << concreteElementB->value << endl; 
		}
};

void Client(){
	ConcreteElementA* elementA = new ConcreteElementA("elementA");
	ConcreteElementB* elementB = new ConcreteElementB("elementB");
	ConcreteVistor1* visitor1 = new ConcreteVistor1();
	ConcreteVistor2* visitor2 = new ConcreteVistor2();
	
	elementA->accept(visitor1);
	elementA->accept(visitor2);

	elementB->accept(visitor1);
	elementB->accept(visitor2);

	delete(elementA);
	delete(elementB);
	delete(visitor1);
	delete(visitor2);
}

int main(){
	Client();

	return 0;
}
