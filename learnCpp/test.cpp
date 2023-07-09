#include <iostream>
using namespace std;
class Beverage{
	public:	
		string name;
 		int num;
 		int much;
		Beverage(int numm, int muchh, string namee){num=numm, much=muchh, name=namee;}
};

class CoinCase{
	private:
		int total=0;
	public:
		void insert(int amount){ total+=amount;	}
		void printTotalCoin(){ cout << "totalCoin: " << total << endl; }
};

class CoinScreen{
	public:
		int coin;
		void printCoin(){cout << "Coin: " << coin << endl; }
}; 
class Button{
	private:
		int whereClicked;
	//	Beverage drink;
	public:
		int outBeverage(Beverage* beverage, int coin){ 
			cout << beverage->name << " Out" << endl;
			int left=coin-beverage->much;
		 	cout <<	"Left Coin: " << left << endl;
			return left;
		}
};
class VendingMachine{
	private:
		CoinCase coinCase;
		Button button;
		CoinScreen coinScreen;
	
		int coin;
		int drink;
	public:
		void run(){cout << "Machine Runs" << endl;}
		int insertCoin(int getCoin){
			cout << "Insert Coin: ";
			cin >> coin;
			coinCase.insert(coin);
			coin += getCoin;
			//coinCase.insert(coin);
			coinCase.printTotalCoin();
			coinScreen.coin=coin;
			coinScreen.printCoin();	
			cout << "Which Beverage: " ;
			cin >> drink;
			Beverage coffee(1, 70, "coffee");
			if(drink==coffee.num)
				coin=button.outBeverage(&coffee, coin);
			return coin;	
		}
};
int main(){
	VendingMachine vm;
	
	vm.run();
	int coin=0;
	while(1){
		cout << "Beverage: only coffee:1" << endl;	
		coin=vm.insertCoin(coin);
		cout << endl;
	}
	return 0;
}
