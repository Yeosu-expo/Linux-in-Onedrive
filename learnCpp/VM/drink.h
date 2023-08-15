#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Drink{
		int price;
	public:
		Drink(int price=0);
		virtual ~Drink();
		int getPrice();
		virtual string getType();
};
#endif
