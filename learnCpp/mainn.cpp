#include <iostream>
using namespace std;

class A{
	public:
		A(){cout << "생성자A" << endl;}
		A(int x) { cout << "A: " << x << endl; }
		~A(){cout << "소멸자A" << endl;}
		void func(){cout << "func:A"<<endl;}
};

class B : public A{
	public:
		B() {cout << "생성자B" << endl;}
		B(int y) : A(y+1) { cout  << "B: " << y << endl; }
		~B(){cout << "소멸자B" << endl;}
		void func(){cout<<"func:B"<<endl;}
};

class C : public B{
	public:
		C(){cout << "생성자C" << endl;}
		~C(){cout << "소멸자C" << endl;}
};

int main(void){
	B b(5);
	b.func();
	return 0;
}
