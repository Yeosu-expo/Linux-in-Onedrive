#include <iostream>
#include "vendingMachine.h"
#include "drink.h"
#include "coffee.h"
#include "alcohol.h"
using namespace std;

int main(int argc, char* argv[]){
	VendingMachine* vm=new VendingMachine();
	vm->run();

	return 0;
}
