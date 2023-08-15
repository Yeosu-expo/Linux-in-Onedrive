#ifndef COFFEE_H
#define COFFEE_H
#include "drink.h"

class Coffee:public Drink{
		string coffeeTpye;
	public:
		~Coffee();
		Coffee(int price=2000, string coffeeTpye="Black Coffee");
		virtual string getType();
};

#endif
