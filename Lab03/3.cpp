/******************************************************************************
Use a circular linked list to solve the Josephus problem:
• N people stand in a circle, eliminating every k-th person until only one survives.
• Input: N = 7, k = 3
• Output: Position of survivor.
• Hint: Use circular traversal and deletion.

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

    void setData(int data) {
        this->data = data;
    }

    ~Node() {
        delete next;
    }
};

Node* getEndNode(Node *start, int k, int iterations) {
         Node *end = start;
         for(int i = 1; i < k - (2 * iterations); i++) {
            if(end->getNext() == nullptr) {
                break;
            }
            end = end->getNext();
         }
         return end;
    }

class LinkedList {
    private:
    Node *head;
    
    public:
    LinkedList(Node *head = nullptr) : head(head) {}

    void setHead(Node *head) {
        this->head = head;
    }

    Node* getHead() {
        return head;
    }

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
    

    friend void reverseList(LinkedList &l, int k) {
        Node *kStart, *kEnd, *current, temp;
        current = l.head;

        while(current != nullptr) {

            kStart = current;
            for(int i = 0; kStart != kEnd; i++){
               

                kEnd = getEndNode(kStart, k, i);
                //  cout << "kEnd" << kEnd->getData() << endl;
                // cout << "0" << endl;
                temp.setData(kEnd->getData());
                kEnd->setData(kStart->getData());
                kStart->setData(temp.getData());
                // cout << "kStart" << kStart->getData() << endl;
                // cout << "kEnd" << kEnd->getData() << endl;

                kStart = kStart->getNext();
            }
            
            
            

            current = getEndNode(current, k, 0);//will point to node at k
            // cout << current->getData();
            current = current->getNext();
            // cout << current->getData();
        }

    }

    
};


// kStart1



int main()
{
    LinkedList l1;
    // cout << "Created ll" << endl;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    // l1.insertAtEnd(6);
    // l1.insertAtEnd(7);
    // l1.insertAtEnd(8);
    // l1.insertAtEnd(9);
    // l1.insertAtEnd(10);


    reverseList(l1, 3);
    l1.display();
    return 0;
}
