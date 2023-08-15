#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component{
	public:
		virtual void fn() = 0;
};

class Leaf:public Component{
	public:
		void fn() { cout << "Leaf" << endl; }
};

class Composite:public Component{
  vector<Component*> vectorCom;
	public:
		void fn(){
			cout << "Composite" << endl;
			for(vector<Component*>::iterator i=vectorCom.begin();i!=vectorCom.end();i++)
				(*i)->fn();	
		}
		void add(Component *component){
			vectorCom.push_back(component);	
		}
};

void Client(){
	Composite *Node1=new Composite();
	Node1->add(new Leaf());
	Node1->add(new Leaf());

	Composite *Node2 = new Composite();
	Node2->add(new Leaf());
	Node2->add(new Leaf());
	Node2->add(new Leaf());

	Composite *Head = new Composite;
	Head->add(Node1);
	Head->add(Node2);
	
	Head->fn();
}

int main(){
	Client();

	return 0;
}
