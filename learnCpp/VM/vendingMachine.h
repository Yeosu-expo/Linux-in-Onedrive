#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
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
		~VendingMachine();
		void run();
		void printAllDrink();
		void putMoney();
		int getChoice();
		void checkQuit(int inputChoice);
		void deductBalance(int inputChoice);
		void outDrink(int inputChoice);
		void deleteDrinkVec();
};
#endif
