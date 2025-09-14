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
        //dont delete next in circular list or it will delete everything
    }
};

class CircularLinkedList {
    private:
    Node *head;
    int size;
    
    public:
    CircularLinkedList(Node *head = nullptr) : head(head), size(0) {}

    void display() {
        if(head == nullptr) {
            cout << "circle is empty bro" << endl;
            return;
        }
        Node *current = head;
        int i = 0;
        cout << "people in circle:" << endl;
        do {
            cout << "person " << current->getData() << " is here" << endl;
            current = current->getNext();
            i++;
        } while(current != head && i < 20); //safety check
        cout << "thats all " << i << " people" << endl;
    }

    void createCircle(int n) {
        if(n <= 0) {
            return;
        }

        head = new Node(1);
        Node *current = head;
        size = 1;

        //add remaining people
        for(int i = 2; i <= n; i++) {
            Node *newPerson = new Node(i);
            current->setNext(newPerson);
            current = newPerson;
            size++;
        }

        //make it circular
        current->setNext(head);
        cout << "created circle with " << n << " people" << endl;
    }

    void removePersonAt(Node *prev) {
        Node *toRemove = prev->getNext();
        
        if(toRemove == head && size == 1) {
            //last person standing
            head = nullptr;
            size = 0;
            return;
        }

        if(toRemove == head) {
            head = head->getNext();
        }

        prev->setNext(toRemove->getNext());
        cout << "person " << toRemove->getData() << " got eliminated" << endl;
        delete toRemove;
        size--;
    }

    int solveJosephus(int k) {
        if(head == nullptr || k <= 0) {
            return -1;
        }

        Node *current = head;
        
        while(size > 1) {
            //move k-1 steps to find the person before the one to eliminate
            for(int i = 1; i < k; i++) {
                current = current->getNext();
            }

            //eliminate the kth person
            removePersonAt(current);

            //move to next person after elimination
            current = current->getNext();
        }

        return head->getData();
    }

    void showSurvivor() {
        if(head != nullptr && size == 1) {
            cout << "person " << head->getData() << " survived!" << endl;
        } else {
            cout << "nobody survived or game not finished" << endl;
        }
    }
};

int main()
{
    CircularLinkedList josephusCircle;
    
    int n = 7;
    int k = 3;
    
    cout << "setting up josephus problem with " << n << " people and k=" << k << endl;
    josephusCircle.createCircle(n);
    josephusCircle.display();

    cout << "\nstarting elimination process" << endl;
    int survivor = josephusCircle.solveJosephus(k);
    
    cout << "\ngame over!" << endl;
    cout << "survivor is at position: " << survivor << endl;
    josephusCircle.showSurvivor();

    //test with different values
    cout << "\n\ntrying another game" << endl;
    CircularLinkedList anotherGame;
    anotherGame.createCircle(5);
    cout << "this time 5 people and k=2" << endl;
    int survivor2 = anotherGame.solveJosephus(2);
    cout << "survivor position:" << survivor2 << endl;

    return 0;
}
