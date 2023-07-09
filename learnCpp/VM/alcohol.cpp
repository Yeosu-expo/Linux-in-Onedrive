#include "alcohol.h"
#include <iostream>

Alcohol::Alcohol(int price=0, string alcoholType="Soju"):Drink(price){
	this->alcoholType=alcoholType;
}

string Alcohol::getType(){
	return alcoholType;
}
