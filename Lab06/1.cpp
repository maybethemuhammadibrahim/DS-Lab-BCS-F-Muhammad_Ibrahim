#include <iostream>
using namespace std;

class Stack {
    int capacity;
    int top; //will bw a pointer
    int *arr; 

    public:
    Stack(int capacity = 10) : capacity(capacity) , top(-1) {
        arr = new int[capacity];
    }

    ~Stack() {
        delete [] arr;
    }

    void push(int data) {
        if(top <= (capacity-1)) {
            arr[++top] = data; 
            cout << data << " inserted into the stack" << endl;
        }
        else {
            cout << "Stack Overflow!" << endl;
        }
    }

    int pop() {
        if(top >= 0) {
            int temp = arr[top];
            top--;
            return temp;
        } 
        else {
            cout << "Stack UnderFlow" << endl;
        }
        return -1;
    }

    int peek() {
        if(top < 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void showStack() {
        for(int i=top; i >= 0; i--) {
            cout << i << "->" << arr[i] << endl;
        }
    }
};

int main() {
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.showStack();
    s.pop();
    cout << endl; 
    s.showStack();

}