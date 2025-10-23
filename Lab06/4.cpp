#include <iostream>
using namespace std;


class Queue {
    int *arr;
    int front, rear; //indexes
    int maxSize;

    public:
    Queue(int maxSize = 3) : maxSize(maxSize), front(-1), rear(-1) {
        arr = new int[maxSize];  
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (front==-1);
    }

    bool isFull() {
        return ((rear + 1) % maxSize == front);
    }

    void enqueue(int data) {
        if(isFull()) {
            cout << "Queue is Full [Cannot insert " << data << " ]" << endl;
            return ;
        }
        if(front == -1) 
            front = 0;
        rear = (rear + 1) % maxSize;
        arr[rear] = data;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int temp = arr[front];        
        if (front == rear) {
        
            front = rear = -1;
        } 
        else {
            front = (front + 1) % maxSize;
        }
        
        return temp;
    }

    void display() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % maxSize;
    }
    cout << endl;
}
};

int main() {
Queue q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.display();

cout << q.dequeue() << endl;;
q.enqueue(4);

q.display();
// cout << endl;
// q.dequeue();
// q.dequeue();
// q.dequeue();
// q.display();
}