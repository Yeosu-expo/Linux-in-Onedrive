#include "alcohol.h"

Alcohol::Alcohol(int price, string alcoholType):Drink(price){
	this->alcoholType=alcoholType;
}

Alcohol::~Alcohol(){
	cout << alcoholType << " 죽을게~" << endl;
}

string Alcohol::getType(){
	return alcoholType;
}
