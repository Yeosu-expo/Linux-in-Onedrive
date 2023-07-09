#include <iostream>
#include "calInfo.h"

Sub::Sub(int n1, int n2, char oper){
	this->n1 = n1;
	this->n2 = n2;
	this->oper = oper;
}

int Sub::process(char oper){
	switch(oper){
		case '+':
			return n1+n2;
		case '-':
			return n1-n2;
		case '/':
			return n1/n2;
		case '*':
			return n1*n2;	
	}	
}
