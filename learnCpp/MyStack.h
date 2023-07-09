#ifndef MYSTACK_H
#define MYSYACK_H
template <class T>
class MyStack{
		T array[100];
		int top=0;
	public:
		MyStack();
		void push(T value);
		void pop();
		bool isEmpty();
		bool isFull();
};

#endif
