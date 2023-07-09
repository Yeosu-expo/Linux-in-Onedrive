#include "calculator.h"
#include <iostream>
using namespace std;

void Calculator::run(){
	cout << "두 개의 수를 입력하세요 >> ";
	int a, b;
	cin >> a >> b;
	Sub sub(a, b);
	cout << sub.process() << endl;
}
