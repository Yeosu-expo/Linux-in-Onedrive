#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

class TableModel{
	string brand;
	string material;

	public:
		TableModel(string brand, string material){
			this->brand = brand;
			this->material = material;	
		}
		string getBrand() { return brand; }
		string getMaterial() { return material; }
};

class Table{
	TableModel *tableModel;
	int x;
	int y;

	public:
		Table(TableModel *tableModel, int x, int y){
			this->tableModel = tableModel;
			this->x = x;
			this->y = y;	
		}
		string getBrand() { return tableModel->TableModel::getBrand(); }
		int getX() { return this->x; }
		int getY() { return this->y; }
};

class TableFactory{
	map<string,TableModel* > tableValue;

	public:
		TableModel* getTableModel(string tableModelValue){
			if(tableValue.find(tableModelValue) != tableValue.end()){
				return tableValue.find(tableModelValue)->second;
			}	
			else{
				istringstream ss(tableModelValue);
				string tmp1;
				string tmp2;
				getline(ss, tmp1,':');
				getline(ss, tmp2,':');
				TableModel *tmpModel = new TableModel(tmp1, tmp2);
				tableValue.insert({tableModelValue, tmpModel});

				return tmpModel;	
			}
		}	
};

void printTable(Table *table){
	cout << table->getBrand() << endl;
	cout << table->getX() << ", " << table->getY() << endl;
}

void Client(){
	TableFactory *tf = new TableFactory();
	Table *t1 = new Table(tf->getTableModel("HiMart:Wood"), 10, 20);
	Table *t2 = new Table(tf->getTableModel("HiMart:Wood"), 20, 20);
	Table *t3 = new Table(tf->getTableModel("HuMart:Wood"), 30, 20);
	
	printTable(t1);
	printTable(t2);
	printTable(t3);

}

int main(){
	Client();

	return 0;
}
