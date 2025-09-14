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
            return;
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

    int getListSize() {
        int count = 0;
        Node *current = head;
        while(current != nullptr) {
            count++;
            current = current->getNext();
        }
        return count;
    }

    void reverseInGroupsOfK(int k) {
        if(head == nullptr || k <= 1) {
            return;
        }

        int totalSize = getListSize();
        Node *newHead = nullptr;
        Node *prevGroupTail = nullptr;
        Node *current = head;

        while(current != nullptr && totalSize >= k) {
            Node *groupHead = current;
            Node *prev = nullptr;
            Node *next = nullptr;

            //reverse k nodes
            for(int i = 0; i < k && current != nullptr; i++) {
                next = current->getNext();
                current->setNext(prev);
                prev = current;
                current = next;
            }

            //prev is now the new head of this group
            if(newHead == nullptr) {
                newHead = prev;
            }

            //connect previous group tail to current group head
            if(prevGroupTail != nullptr) {
                prevGroupTail->setNext(prev);
            }

            //groupHead is now the tail of current group
            prevGroupTail = groupHead;
            totalSize -= k;
        }

        //connect remaining nodes if any
        if(prevGroupTail != nullptr) {
            prevGroupTail->setNext(current);
        }

        head = newHead;
    }

    void displayInLine() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = head;
        while(current != nullptr) {
            cout << current->getData();
            if(current->getNext() != nullptr) {
                cout << " -> ";
            }
            current = current->getNext();
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    
    //creating the example list
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(8);

    cout << "Original List:" << endl;
    list.displayInLine();

    cout << "\nReversing in groups of 3:" << endl;
    list.reverseInGroupsOfK(3);
    list.displayInLine();

    //test with another k value
    LinkedList list2;
    list2.insertAtEnd(1);
    list2.insertAtEnd(2);
    list2.insertAtEnd(3);
    list2.insertAtEnd(4);
    list2.insertAtEnd(5);
    list2.insertAtEnd(6);

    cout << "\nOriginal List:" << endl;
    list2.displayInLine();

    cout << "Reversing in groups of 2:" << endl;
    list2.reverseInGroupsOfK(2);
    list2.displayInLine();

    return 0;
}
