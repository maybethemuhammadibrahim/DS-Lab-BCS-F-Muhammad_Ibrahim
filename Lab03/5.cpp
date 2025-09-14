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

class DoublyNode {
    private:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    public:
    DoublyNode(int data = 0, DoublyNode *next = nullptr, DoublyNode *prev = nullptr) : data(data), next(next), prev(prev) {}

    int getData() {
        return data;
    }
    
    void setNext(DoublyNode* node) {
        this->next = node;
    }

    DoublyNode* getNext() {
        return next;
    }

    void setPrev(DoublyNode* node) {
        this->prev = node;
    }

    DoublyNode* getPrev() {
        return prev;
    }

    ~DoublyNode() {
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

    DoublyNode* convertToDoubly() {
        if(head == nullptr) {
            return nullptr;
        }

        DoublyNode *doublyHead = new DoublyNode(head->getData());
        DoublyNode *doublyCurrent = doublyHead;
        Node *current = head->getNext();

        while(current != nullptr) {
            DoublyNode *newDoublyNode = new DoublyNode(current->getData());
            doublyCurrent->setNext(newDoublyNode);
            newDoublyNode->setPrev(doublyCurrent);
            doublyCurrent = newDoublyNode;
            current = current->getNext();
        }

        return doublyHead;
    }

    Node* convertToCircular() {
        if(head == nullptr) {
            return nullptr;
        }

        Node *circularHead = new Node(head->getData());
        Node *circularCurrent = circularHead;
        Node *current = head->getNext();

        while(current != nullptr) {
            Node *newCircularNode = new Node(current->getData());
            circularCurrent->setNext(newCircularNode);
            circularCurrent = newCircularNode;
            current = current->getNext();
        }

        //make it circular by connecting last to first
        circularCurrent->setNext(circularHead);
        
        return circularHead;
    }
};

class DoublyLinkedList {
    private:
    DoublyNode *head;
    
    public:
    DoublyLinkedList(DoublyNode *head = nullptr) : head(head) {}

    void displayForward() {
        if(head == nullptr) {
            cout << "Doubly List is empty" << endl;
            return;
        }
        DoublyNode *current = head;
        int i = 0;
        cout << "Forward Display:" << endl;
        while(current != nullptr) {
            cout << i+1 << " :" << current->getData() << endl;
            current = current->getNext();
            i++;
        }
        cout << "Forward Display Completed with " << i << " items" << endl;
    }

    void displayBackward() {
        if(head == nullptr) {
            cout << "Doubly List is empty" << endl;
            return;
        }

        //go to last node first
        DoublyNode *current = head;
        while(current->getNext() != nullptr) {
            current = current->getNext();
        }

        int i = 0;
        cout << "Backward display:" << endl;
        while(current != nullptr) {
            cout << i+1 << " :" << current->getData() << endl;
            current = current->getPrev();
            i++;
        }
        cout << "Backward display Completed with " << i << " items" << endl;
    }
};

class CircularLinkedList {
    private:
    Node *head;
    
    public:
    CircularLinkedList(Node *head = nullptr) : head(head) {}

    void displayCircular() {
        if(head == nullptr) {
            cout << "Circular List is empty" << endl;
            return;
        }

        Node *current = head;
        int i = 0;
        cout << "Circular Display:" << endl;
        do {
            cout << i+1 << " :" << current->getData() << endl;
            current = current->getNext();
            i++;
        } while(current != head && i < 20); 

        cout << "Circular Display Completed with " << i << " items" << endl;
    }
};

int main()
{
    LinkedList originalList;
    originalList.insertAtEnd(10);
    originalList.insertAtEnd(20);
    originalList.insertAtEnd(30);
    originalList.insertAtEnd(40);
    originalList.insertAtEnd(50);

    cout << "Original singly linked list:" << endl;
    originalList.display();

    cout << "\nConverting to doubly linked list" << endl;
    DoublyNode *doublyHead = originalList.convertToDoubly();
    DoublyLinkedList doublyList(doublyHead);
    doublyList.displayForward();
    doublyList.displayBackward();

    cout << "\nConverting to circular linked list" << endl;
    Node *circularHead = originalList.convertToCircular();
    CircularLinkedList circularList(circularHead);
    circularList.displayCircular();

    return 0;
}
