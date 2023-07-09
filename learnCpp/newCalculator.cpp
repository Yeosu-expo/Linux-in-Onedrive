#include "newCalculator.h"
#include <iostream>
using namespace std;

void Calculator::run(){
	cout << "연산을 입력하세요 >> ";
	int a, b;
	char operate
	cin >> a >> b >> operate;
	CalInfo calInfo(a, b, operate);
	cout << calInfo.process() << endl;
}
