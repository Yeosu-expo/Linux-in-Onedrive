using namespace std;
template <class T>
class MyStack{
                T array[100];
                int top=0;
        public:
                MyStack<T>();
                void push(T value);
                void pop();
                bool isEmpty();
                bool isFull();
};

template <class T>
MyStack<T>::MyStack(){
        top=0;
}

template <class T>
void MyStack<T>::push(T value){
        if(isFull()){
                cout << "isFull!!!" << endl;
                return;
        }
        array[top++]=value;
}

template <class T>
void MyStack<T>::pop(){
        if(isEmpty()){
                cout << "isEmpty!!!" << endl;
                return;
        }
        cout << "POP: " << array[top-1] << endl;
        array[top-1]=0;
        top--;
}

template <class T>
bool MyStack<T>::isEmpty(){
        if(top==0) return true;
        return false;
}

template <class T>
bool MyStack<T>::isFull(){
        if(top==101) return true;
        return false;
}
