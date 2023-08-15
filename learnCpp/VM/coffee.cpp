#include "coffee.h"

Coffee::Coffee(int price,string coffeeTpye):Drink(price){
	this->coffeeTpye=coffeeTpye;
}

Coffee::~Coffee(){
	cout << coffeeTpye << " 죽을게~" << endl;
}

string Coffee::getType(){
	return coffeeTpye;
}
