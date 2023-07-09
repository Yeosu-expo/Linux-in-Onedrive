#include "coffee.h"
#include <iostream>
#include <string>
#include <vector>

Coffee::Coffee(int price=0,string coffeeTpye="BlackCoffee"):Drink(price){
	this->coffeeTpye=coffeeTpye;
}

string Coffee::getType(){
	return coffeeTpye;
}
