#include <iostream>
using namespace std;

class MultiNode {
    private:
    int data;
    MultiNode* next;
    MultiNode* child;
    public:
    MultiNode(int data = 0, MultiNode *next = nullptr, MultiNode *child = nullptr) : data(data), next(next), child(child) {}

    int getData(){
        return data;
    }
    
    void setNext(MultiNode* node){
        this->next = node;
    }

    MultiNode* getNext(){
        return next;
    }

    void setChild(MultiNode* node){
        this->child = node;
    }

    MultiNode* getChild(){
        return child;
    }

    ~MultiNode() {
        delete next;
        delete child;
    }
};

class Node {
    private:
    int data;
    Node* next;
    public:
    Node(int data = 0, Node *next = nullptr) : data(data) , next(next) {}

    int getData(){
        return data;
    }
    
    void setNext(Node* node){
        this->next = node;
    }

    Node* getNext() {
        return next;
    }

    ~Node() {
        delete next;
    }
};

class MultiLevelLinkedList {
    private:
    MultiNode *head;
    
    public:
    MultiLevelLinkedList(MultiNode *head = nullptr) : head(head) {}

    void display() {
        if(head == nullptr) {
            cout << "Multi Level List is empty" << endl;
            return;
        }
        MultiNode *current = head;
        int i = 0;
        while(current != nullptr) {
            cout << i+1 << " :" << current->getData();
            if(current->getChild() != nullptr) {
                cout << " (has child)";
            }
            cout << endl;
            current = current->getNext();
            i++;
        }
        cout << "Display Completed with " << i << " items" << endl;
    }

    void insertAtEnd(int newData) {
        MultiNode *newNode = new MultiNode(newData);
        if(head == nullptr) {
            head = newNode;
            cout << "Created new node at head" << endl;
            return;
        }

        MultiNode *current = head;
        while(current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }

    void addChild(int parentData, int childData) {
        MultiNode *current = head;
        while(current != nullptr) {
            if(current->getData() == parentData) {
                MultiNode *childNode = new MultiNode(childData);
                if(current->getChild() == nullptr) {
                    current->setChild(childNode);
                } else {
                    //add to end of child list
                    MultiNode *childCurrent = current->getChild();
                    while(childCurrent->getNext() != nullptr) {
                        childCurrent = childCurrent->getNext();
                    }
                    childCurrent->setNext(childNode);
                }
                return;
            }
            current = current->getNext();
        }
    }

    Node* flattenList() {
        if(head == nullptr) {
            return nullptr;
        }

        Node *flatHead = nullptr;
        Node *flatTail = nullptr;
        MultiNode *current = head;

        while(current != nullptr) {
            //add current node to flat list
            Node *newFlatNode = new Node(current->getData());
            if(flatHead == nullptr) {
                flatHead = newFlatNode;
                flatTail = newFlatNode;
            } else {
                flatTail->setNext(newFlatNode);
                flatTail = newFlatNode;
            }

            //if current has child add all child nodes
            if(current->getChild() != nullptr) {
                MultiNode *childCurrent = current->getChild();
                while(childCurrent != nullptr) {
                    Node *childFlatNode = new Node(childCurrent->getData());
                    flatTail->setNext(childFlatNode);
                    flatTail = childFlatNode;
                    childCurrent = childCurrent->getNext();
                }
            }

            current = current->getNext();
        }

        return flatHead;
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
        cout << "Display completed with " << i << " items" << endl;
    }
};

int main()
{
    MultiLevelLinkedList multiList;
    
    //create the example structure
    multiList.insertAtEnd(1);
    multiList.insertAtEnd(2);
    multiList.insertAtEnd(3);
    
    //add child to node with data 1
    multiList.addChild(1, 4);
    multiList.addChild(1, 5);

    cout << "Multi level linked List:" << endl;
    multiList.display();

    cout << "\nFlattening the list" << endl;
    Node *flattenedHead = multiList.flattenList();
    LinkedList flatList(flattenedHead);
    flatList.display();

    return 0;
}
