#include <iostream>
#include "sub.h"

Sub::Sub(int n1, int n2){
	this->n1 = n1;
	this->n2 = n2;
}

int Sub::process(){
	return n1-n2;
}
