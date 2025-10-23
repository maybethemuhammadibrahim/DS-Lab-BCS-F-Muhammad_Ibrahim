#include <iostream>
using namespace std;

void shiftArrLeft(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = arr[i+1];
    }
    arr[size] = 0;
}

class Queue {
    int *arr;
    int front, rear; //indexes
    int maxSize;

    public:
    Queue(int maxSize = 10) : maxSize(maxSize), front(-1), rear(-1) {
        arr = new int[maxSize];  
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        if(front == -1 || rear == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() {
        if(rear >= maxSize-1) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data) {
        if(isFull()) {
            cout << "Queue is Full" << endl;
            return ;
        }
        if(front==-1) {
            front = 0;
        }
        arr[++rear] = data;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is Emty" << endl;
            return -1;
        }
        int temp = arr[front];        
        shiftArrLeft(arr, rear);
        rear--;
        return temp;
    }

    void display() {
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
Queue q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.display();
cout << endl;
q.dequeue();
q.dequeue();
q.display();
}