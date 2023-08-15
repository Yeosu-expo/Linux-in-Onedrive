#include "drink.h"

Drink::~Drink()	{}

Drink::Drink(int price){
	this->price = price;
}

int Drink::getPrice(){
	return price;
}

string Drink::getType(){
	return "soldOut";
}
