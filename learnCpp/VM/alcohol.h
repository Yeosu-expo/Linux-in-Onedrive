#ifndef ALCOHOL_H
#define ALCOHOL_H
#include "drink.h"
#include "coffee.h"
class Alcohol:public Drink{
		string alcoholType;
	public:
		~Alcohol();
		Alcohol(int price=2500, string alcoholType="Soju");
		virtual string getType();
};
#endif
