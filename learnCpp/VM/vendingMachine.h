#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <iostream>
#include <string>
#include <vector>
#include "drink.h"
#include "coffee.h"
#include "alcohol.h"
using namespace std;

class VendingMachine{
		vector<Drink*> drinkVec;
		int moneyBox;
		int leftMoney;
		bool isRun;
	public:
		VendingMachine();
		void run();
		void printAllDrink();
		void putMoney();
		int getChoice();
		void checkQuit(int inputChoice);
		void deductBalance(int inputChoice);
		void outDrink(int inputChoice);
};
#endif
