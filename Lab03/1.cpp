/******************************************************************************
1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise.

*******************************************************************************/
#include <iostream>
using namespace std;

class Node {
    private:
    int data;
    Node* next;
    public:
    Node(int data = 0, Node *next = nullptr) : data(data) , next(next) {}

    int getData() {
        return data;
    }
    
    void setNext(Node* node) {
        this->next = node;
    }

    Node* getNext() {
        return next;
    }

    ~Node() {
        delete next;
    }
};

class LinkedList {
    private:
    Node *head;
    
    public:
    LinkedList(Node *head = nullptr) : head(head) {}

    void display() {
        if(head == nullptr) {
            cout << "Linked List is empty" << endl;
        }
        Node *current = head;
        int i = 0;
        while(current != nullptr) {
            cout << i+1 << " :" << current->getData() << endl;
            current = current->getNext();
            i++;
        }
        cout << "Display Completed with " << i << " items" << endl;
    }

    void insertAtEnd(int newData) {
        Node *newNode = new Node(newData);
        if(head == nullptr) {
            head = newNode;
            cout << "Created new node at head" << endl;
            return;
        }

        Node *current  = head;
        while(current->getNext() != nullptr) {
            current = current->getNext();
        }
        if(current->getNext() == nullptr) {
            current->setNext(newNode);
        }
        
    }

    bool isPalindrome() {
        Node *currentHead, *tempCurrent, *tempTail;
        currentHead = head;
        Node *currentTail = nullptr;
        while (currentHead->getNext() != nullptr) {

            //in each iteration of outer loop this inner loop will
            //make currentTail point to (size - i) node
            
            //while currentHead is a pointer that increments 
            //by one node in each iteration
            tempCurrent = head;
            while(tempCurrent->getNext() != currentTail) {
                tempCurrent = tempCurrent->getNext();
            }

            currentTail = tempCurrent;

            if(currentHead->getData() != currentTail->getData()) {
                return false;
            }

            currentHead = currentHead->getNext();

        }
        return true;
    }
    
    
};


int main()
{
    LinkedList l1;
    // cout << "Created ll" << endl;
    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);
    l1.insertAtEnd(30);
    l1.insertAtEnd(20);
    l1.insertAtEnd(10);
    // l1.display();
    cout << l1.isPalindrome() << endl;
    return 0;
}
