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
    Node(int data = 0, Node* next = nullptr) : data(data) , next(next) {}

    int getData() {
        return data;
    }
    
    void setNext(Node* node) {
        this->next = node;
    }

    Node* getNext() {
        return next;
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
        while(current->getNext() != nullptr) {
            cout << i+1 << " :" << current->getData() << endl;
            current = current->getNext();
            i++;
        }
        cout << "Display Completed with " << i << " items" << endl;
    }

    void insertAtEnd(int newData) {
        
        if(head == nullptr) {
            head->setNext(new Node(newData));
        }

        Node *current  = head;
        while(current->getNext() != nullptr) {
            Node *newNode = new Node(newData);
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            current = current->getNext();
        }
    }
    
    
};


int main()
{
    LinkedList l1;
    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);
    l1.insertAtEnd(40);
    l1.insertAtEnd(50);

    l1.display();
    return 0;
}
