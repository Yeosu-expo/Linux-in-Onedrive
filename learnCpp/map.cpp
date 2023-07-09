#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string, string> m;
	m["홍길동"]="Hong";
	m["김길동"]="Kim";

	map<string, string>::iterator it;

	for(it=m.begin();it!=m.end();it++){
		cout << it->first << ":" << it->second << endl;	
	}
	return 0;
}
