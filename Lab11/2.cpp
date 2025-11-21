#include <iostream>
using namespace std;

#define TABLE_SIZE 100

struct Node {
    string data;
    Node* next;

    Node(string data) : data(data), next(nullptr) {}
};

class Hash{
    Node* hashTable[TABLE_SIZE];

    int hash(string key) {
        int sum = 0;
        for(int i = 0;i < key.length(); i++) {
            sum += key[i];
        }
        return sum % TABLE_SIZE;
    }

    public:
    Hash() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = nullptr;
        }
    }

    void add_record(string data) {
    int index = hash(data);

    Node* newNode = new Node(data);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    }

    bool search(string word) {
        int index = hash(word);

        Node* cur = hashTable[index];
        while(cur !=nullptr) {
            if(cur->data == word) {
                cout << "Word is present in dictionary at index " << index << endl;
                return true;
            }
            cur = cur->next;
        }

        cout << "Word is not present in dictionary"  << endl;
        return false;

    }

    void displayDict() {

        for(int i = 0; i < TABLE_SIZE; i++) {
            Node* curr = hashTable[i];
            while(curr) {
                cout << curr->data << endl;
                curr = curr->next;
            }
        }
        
    }
};

int main() {
    Hash table;
    table.add_record("aaaaa");
    table.add_record("bbbbb");
    table.add_record("acccc");
    table.add_record("zzzzz"); 
    table.displayDict();
    // Node* temp = table.search("A");
    // cout << temp->data << " " << temp->key << endl;

}
