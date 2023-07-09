#ifndef COFFEE_H
#define COFFEE_H
#include <iostream>
#include <string>
#include <vector>
#include "drink.h"
#include "alcohol.h"

class Coffee:public Drink{
		string coffeeTpye;
	public:
		Coffee();
		Coffee(int price, string coffeeTpye);
		virtual string getType();
};

#endif
