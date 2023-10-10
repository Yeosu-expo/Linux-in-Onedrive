#include <iostream>
using namespace std;

void addNode(int* tree, int pos, int data){
	tree[pos] = data;
}

void printTree(int* tree, int height){
			
}

void searchTree(int* tree, int data){
	
}

int main(){
	cout << "tree height? " ;
	int height;
	cin >> height;

	int tree[2^height];
	int maxSize = 2^height - 1;

	cout << "트리 데이터 입력을 시작합니다. (max size == " << maxSize << ")" << endl;
	while(true){
		int pos, data;
		cout << "pos, data = ? " ;
		cin >> pos >> data;

		if(pos==0||pos>maxSize)
			break;
		addNode(tree, pos, data);	
	}
	cout << "트리 데이터 입력이 완료되었습니다." << endl;

	printTree(tree, height);

	while(true){
		int data;
		cout << "정보를 알고 싶은 데이터를 입력하세요 (종료 = 999) : " ;
		cin >> data;

		if(data==999)
			break;
		searchTree(tree, data);
	}
	cout << "종료합니다." << endl;

	return 0;
}
