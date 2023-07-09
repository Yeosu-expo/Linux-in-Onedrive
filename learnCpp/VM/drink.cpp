#include "drink.h"
#include <iostream>
#include <string>
#include <vector>

Drink::Drink(int price=0){
	this->price = price;
}

int Drink::getPrice(){
	return price;
}

string Drink::getType(){
	return "soldOut";
}
