/******************************************************************************
Implement a function to merge two sorted singly linked lists into one sorted list.

Lab Manual 03

• Example:
o List A: 1 → 3 → 5
o List B: 2 → 4 → 6
o Output: 1 → 2 → 3 → 4 → 5 → 6
• Bonus: Solve without creating new nodes (rearrange pointers).

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

    //merging onto the linked list whose first element is smaller in value
    //will return the head pointer of newly formed ll, only this Node pointer would be created

    friend Node* mergeLL(LinkedList &l1, LinkedList &l2) {
        Node *headA = l1.head;
        Node *headB = l2.head;
        Node *newHead;


        Node *newListPointer;
        Node *currentA = headA;
        Node *currentB = headB;
        // cout << currentA->getData() << endl;
        // cout << currentB->getData() << endl;

        //choosing the first node for the merged list
        if(currentA->getData() <= currentB->getData()) {
            newHead = headA;
            // cout << currentA->getData() << endl;
            currentA = currentA->getNext();
            
        }
        else if(currentA->getData() > currentB->getData()) {
            newHead = headB;
            cout << currentB->getData() << endl;
            currentB = currentB->getNext();
        }
        newListPointer = newHead;

        // cout << currentA->getData() << endl;
        // cout << currentB->getData() << endl;
        


        //merging the lists
        while(currentA != nullptr && currentB != nullptr) {

            if(currentA->getData() <= currentB->getData() && currentA != nullptr) {
                newListPointer->setNext(currentA);
                // cout << newListPointer->getData() << endl;
                currentA = currentA->getNext();
                
                
            }
            else if (currentB->getData() < currentA->getData() && currentB != nullptr){
                newListPointer->setNext(currentB);
                // cout << currentA->getData() << endl;
                currentB = currentB->getNext();
                
            }
            else {
                cout << "Some Error has occured" << endl;
            }
            newListPointer = newListPointer->getNext();
            // cout << currentA->getData() << endl;
            // cout << currentB->getData() << endl;
            // cout << newListPointer->getData() << endl;
        }
        if(currentA == nullptr) {
            newListPointer->setNext(currentB);
        }
        else if(currentB == nullptr){
            newListPointer->setNext(currentA);
        }


        return newHead;
        
}

    
};



int main()
{
    LinkedList l1,l2,l3;
    // cout << "Created ll" << endl;
    l1.insertAtEnd(1);
    l1.insertAtEnd(3);
    l1.insertAtEnd(5);

    l2.insertAtEnd(2);
    l2.insertAtEnd(4);
    l2.insertAtEnd(6);
    l2.insertAtEnd(10);
    
    l1.display();
    l2.display();

    l3.setHead(mergeLL(l1, l2));
    l3.display();
    
    
    return 0;
}
