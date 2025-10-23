#include <iostream>
using namespace std;

//assuming the stack will store what was the last direction
//of a player in a game
//1-north
//2-east
//3-south
//4-west
struct Node {
    int direction;
    Node *next;

    Node(int data = -1) : direction(data), next(nullptr) {}
};

class Stack {
    int capacity;
    Node *top; //will bw a pointer 

    public:
    Stack(int capacity = 10) : capacity(capacity) , top(nullptr) {
    }

    ~Stack() {
    }

    void push(int data) {
    Node *n = new Node(data);
    if(top == nullptr) {
        top = n;
    } else {
        n->next = top;
        top = n;
    }
    cout << data << " inserted" << endl;
}

    int pop() {
        if(top == nullptr) {
            cout << "Stack UnderFlow" << endl;
        } 
        Node *temp = top;
        top = top->next;
        int data = temp->direction;
        delete temp;
        return data;

    }

    int peek() {
        if(top == nullptr) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->direction;
    }

    void showStack() {
        Node *curr = top;
        if(top == nullptr) {
            cout << "Stack is Empty" << endl;
        }
        while(curr != nullptr) {
            cout << curr->direction << endl;
            curr = curr->next;
        }

    }
};

int main() {
    Stack s;
    s.push(1);
    // cout << s.peek() << endl;
    s.push(2);
    s.push(3);
    s.push(4);
    s.showStack();
    s.pop();
    cout << endl; 
    s.showStack();

}