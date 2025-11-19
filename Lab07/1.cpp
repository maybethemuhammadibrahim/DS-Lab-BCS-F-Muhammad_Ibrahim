#include <iostream>
using namespace std;

class StudentRecord
{
private:
    string name;
    int score;

public:
    StudentRecord(string name, int score) : name(name), score(score) {}

    string getName() const { return this->name; }
    int getScore() const { return this->score; }
};

struct Node
{
    StudentRecord record;
    Node *next;

    Node(StudentRecord r) : record(r), next(nullptr) {}
};

class LL
{
    Node *head;
    int size;

public:
    LL(Node *head = nullptr) : head(head), size(0) {}

    ~LL()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    Node *getHead() { return head; }
    int getSize() { return size; }

    void insertNode(string name, int score)
    {
        StudentRecord data(name, score);
        Node *n = new Node(StudentRecord(data));
        if (head == nullptr)
        {
            head = n;
            return;
        }

        Node *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = n;
        size++;
    }

    void deleteNode(string name, int score)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->record.getName() == name && head->record.getScore() == score)
        {
            Node *del = head;
            head = head->next;
            delete head;
        }
        Node *curr = head;
        while (curr->next)
        {
            if (curr->next->record.getName() == name && curr->next->record.getScore() == score)
            {
                Node *temp = curr->next->next;
                Node *del = curr->next;
                curr->next = temp;
                delete del;
            }
            curr = curr->next;
        }
        size--;
    }

    void displayNodes()
    {
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }
        Node *curr = head;
        while (curr)
        {
            cout << curr->record.getName() << " , " << curr->record.getScore() << endl;
            curr = curr->next;
        }
    }

    void radixSort()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        int max = 100;
        int exp = 1;

        while (max / exp > 0)
        {

            LL *buckets[10];
            for (int i = 0; i < 10; i++)
            {
                buckets[i] = new LL();
            }

            Node *curr = head;
            while (curr != nullptr)
            {
                int digit = (curr->record.getScore() / exp) % 10;
                buckets[digit]->insertNode(curr->record.getName(), curr->record.getScore());
                curr = curr->next;
            }

            head = nullptr;
            Node *tail = nullptr;

            for (int i = 0; i < 10; i++)
            {
                if (buckets[i]->head != nullptr)
                {
                    if (head == nullptr)
                    {
                        head = buckets[i]->head;
                        tail = buckets[i]->head;
                    }
                    else
                    {
                        tail->next = buckets[i]->head;
                    }

                    while (tail->next != nullptr)
                    {
                        tail = tail->next;
                    }
                }

                buckets[i]->head = nullptr;
                delete buckets[i];
            }

            exp *= 10;
        }
    }
    Node* calculateMid() {
        if (head == nullptr) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node* previousNode(Node* mid) {
        if(mid == nullptr) return nullptr;
        Node* curr = head;
        while(curr->next != mid) {
            curr = curr->next;
        }
        return curr;
    }

    Node* getTail() {
        if(!head) return nullptr;

        Node* curr = head;
        while(curr->next) {curr = curr->next;}
        return curr;
    }

    void deleteNode(Node* mid) {
        Node* midPre = previousNode(mid);
        Node* midNext = mid->next;
        delete mid;
        midPre->next = midNext;
    }

    void deleteItem(string name, int score)
    {
        Node* left = head;
        Node* right = getTail();

        while(left->record.getScore() <= right->record.getScore() ) {
            Node* mid = this->calculateMid();
            if(mid->record.getName() == name && mid->record.getScore() == score) {
                deleteNode(mid);
            }
            else if(mid->record.getScore() < score) {
                left = mid->next;
            }
            else {
                right = previousNode(mid);
            }
            
        }
    }
};

int main()
{
    LL Students;
    Students.insertNode("Ayan", 90);
    Students.insertNode("Zameer", 60);
    Students.insertNode("Sara", 70);
    Students.insertNode("Sohail", 30);
    Students.insertNode("Ahmed", 20);

    Students.radixSort();

    cout << "Sorted List: "<< endl;
    Students.displayNodes();

    cout << "List after deleting Sara: "<< endl;
    Students.deleteNode("Sara", 70);

    Students.displayNodes();
}
