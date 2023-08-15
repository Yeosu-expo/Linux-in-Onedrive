#include <iostream>
#include <string>
using namespace std;

class Cat{
	public:
		virtual void descCat() = 0;
};

class MyCat:public Cat{
	public:
		void descCat(){
			cout << "MyCat: ";		
		}
};

class DecoratorCat:public Cat{
	Cat *cat;
	public:
		DecoratorCat(Cat *cat) { this->cat = cat; }
		void descCat(){
			cat->descCat();	
		}
		virtual void descDeco() = 0;
};

class BlackCat:public DecoratorCat{
	private:
		void descDeco(){
			cout << "Black ";	
		}
	public:
		BlackCat(Cat *cat):DecoratorCat(cat){}
		void descCat(){
			DecoratorCat::descCat();
			this->descDeco();
		}
};

class SpottedCat:public DecoratorCat{
	private:
		void descDeco(){
			cout << "Spotted ";	
		}
	public:
		SpottedCat(Cat *cat):DecoratorCat(cat){}
		void descCat(){
			DecoratorCat::descCat();
			this->descDeco();		
		}
};

void Client(){
	Cat *blackCat = new BlackCat(new MyCat());
	blackCat->descCat();
	cout << endl;

	Cat *blackSpottedCat = new BlackCat(new SpottedCat(new MyCat()));
	blackSpottedCat->descCat();
	cout << endl;
}

int main(){
	Client();

	return 0;
}
