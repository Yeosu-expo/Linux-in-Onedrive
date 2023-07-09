#include "vendingMachine.h"
#include <iostream>

VendingMachine::VendingMachine(){
	moneyBox=0;
	leftMoney=0;
	isRun=true;
	drinkVec.push_back(new Coffee(3500, "Latte"));
	drinkVec.push_back(new Alcohol(50000, "AbsolutVodka"));
	drinkVec.push_back(new Coffee(15000, "PremiumAmericano"));
	drinkVec.push_back(new Alcohol(14900, "WON SOJU"));
	drinkVec.push_back(new Coffee(100000, "Random Drink"));
}

void VendingMachine::run(){
	while(1){
		printAllDrink();
		putMoney();
		int inputChoice = getChoice();
		checkQuit(inputChoice);
		if(this->isRun==false) return;
		outDrink(inputChoice);
	}
}

void VendingMachine::printAllDrink(){
	for(int i=0;i<drinkVec.size();i++){
		cout << i+1 << ": " << drinkVec[i]->getType() << " >> " << drinkVec[i]->getPrice() << "원" << endl;
	}
	cout << drinkVec.size()+1 << ": Quit" << endl;
	cout << endl;
}

void VendingMachine::putMoney(){
	cout << "your balance: " << leftMoney << endl;
	cout << "Put money >> ";
	int tmp;
	cin >> tmp;
	leftMoney+=tmp;
	cout << "now your balance: " << leftMoney << endl;
}

int VendingMachine::getChoice(){
	cout << "Which drink? ";
	int input;
	cin >> input;

	return input-1;
}

void VendingMachine::checkQuit(int inputChoice){
	if(inputChoice==drinkVec.size()){
		isRun=false;
		cout << "멀리 안나간다~" << endl;
		return;
	}
	deductBalance(inputChoice);
	return;
}

void VendingMachine::deductBalance(int inputChoice){
	int drinkPrice=drinkVec[inputChoice]->getPrice();
	if(leftMoney < drinkPrice){
		cout << "어린노무 시키가!\nGET OUT!" << endl;
		isRun=false;
		return;
	}
	leftMoney -= drinkPrice;
}

void VendingMachine::outDrink(int inputChoice){
	if(drinkVec[inputChoice]->getType()=="Random Drink"){
		cout << "꽝!" << endl << endl;
		return;
	}
	cout << drinkVec[inputChoice]->getType() << " OUT!" << endl;
	cout << "Well Thank you." << endl << endl;
}

