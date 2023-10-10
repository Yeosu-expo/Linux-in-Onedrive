#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* allocNode(int data){
	Node* node = new Node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;

	return node;
}

void recall(int type,Node* node){
	if(type==1) cout << node->data << " ";
	if(node->left!=NULL) recall(type, node->left);
	if(type==2) cout << node->data << " ";
	if(node->right!=NULL) recall(type, node->right);
	if(type==3) cout << node->data << " ";

	return;
}

void recall2(queue<Node*>* q){
	if(q->empty())
		return;
	if(q->front()->left!=NULL) q->push(q->front()->left);
	if(q->front()->right!=NULL) q->push(q->front()->right);
	printf("%d ", q->front()->data);
	q->pop();
	recall2(q);
}

int main(){
	Node* root = allocNode(1);
	Node* Lleaf = allocNode(2);
	Node* Rleaf = allocNode(3);

	root->left = Lleaf;
	root->right = Rleaf;
	root->left->left = allocNode(4);
	root->left->right = allocNode(5);
	root->right->left = allocNode(6);
	root->right->right = allocNode(7);

	root->left->left->left = allocNode(8);
	root->left->left->right = allocNode(9);
	root->left->right->left = allocNode(10);
	root->left->right->right = allocNode(11);


	for(int i=1;i<=3;i++){
		recall(i, root);
		cout << endl;	
	}

	queue<Node*>* q = new queue<Node*>;
	q->push(root);
	cout << endl;
	recall2(q);
	cout << endl;

	return 0;
}
