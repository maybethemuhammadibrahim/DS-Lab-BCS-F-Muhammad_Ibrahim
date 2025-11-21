#include <iostream>
using namespace std;

#define TABLE_SIZE 20

struct Node {
    string key;
    string data;
    Node* next;

    Node(string key, string data) : key(key), data(data), next(nullptr) {}
};

class Hash{
    Node* hashTable[TABLE_SIZE];

    int hash(string key) {
        int sum = 0;
        for(int i = 0;i < key.length(); i++) {
            sum += key[i];
        }
        return (sum / TABLE_SIZE);
    }

    public:
    Hash() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = nullptr;
        }
    }

    void insert(string key, string data) {
    int index = hash(key);

    Node* cur = hashTable[index];
    while (cur != nullptr) {
        if (cur->key == key) {
            cur->data = data;
            return;
        }
        cur = cur->next;
    }

    Node* newNode = new Node(key, data);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}
    Node* search(string key) {
        int index = hash(key);

        Node* cur = hashTable[index];
        while(cur !=nullptr) {
            if(cur->key == key) {
                return cur;
            }
            cur = cur->next;
        }
    }

    void displayLinkedList(string key) {
        int index = hash(key);
        Node* curr = hashTable[index];
        while(curr) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};

int main() {
    Hash table;
    table.insert("A", "aaaaa");
    table.insert("B", "bbbbb");
    table.insert("C", "acccc");
    table.insert("A", "zzzzz"); //update A key

    table.displayLinkedList("A");
    // Node* temp = table.search("A");
    // cout << temp->data << " " << temp->key << endl;

}
