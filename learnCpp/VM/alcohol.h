#ifndef ALCOHOL_H
#define ALCOHOL_H
#include <iostream>
#include <string>
#include "drink.h"
#include "coffee.h"
class Alcohol:public Drink{
		string alcoholType;
	public:
		Alcohol();
		Alcohol(int price, string alcoholType);
		virtual string getType();
};
#endif
