#include <iostream>
using namespace std;

class HashNode {
public:
    int sum;
    int first;
    int second;
    HashNode* next;
    
    HashNode(int s, int f, int sec) {
        sum = s;
        first = f;
        second = sec;
        next = nullptr;
    }
};

class HashTable {
private:
    HashNode** table;
    int capacity;
    
    int hashFunction(int key) {
        return key % capacity;
    }
    
public:
    HashTable(int cap) {
        capacity = cap;
        table = new HashNode*[capacity];
        for(int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    }
    
    bool insert(int sum, int first, int second, int& a, int& b, int& c, int& d) {
        int index = hashFunction(sum);
        HashNode* current = table[index];
        
        while(current != nullptr) {
            if(current->sum == sum) {
                if(current->first != first && current->first != second && 
                   current->second != first && current->second != second) {
                    a = current->first;
                    b = current->second;
                    c = first;
                    d = second;
                    return true;
                }
            }
            current = current->next;
        }
        
        HashNode* newNode = new HashNode(sum, first, second);
        newNode->next = table[index];
        table[index] = newNode;
        return false;
    }
    
    ~HashTable() {
        for(int i = 0; i < capacity; i++) {
            HashNode* current = table[i];
            while(current != nullptr) {
                HashNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

void findPairs(int arr[], int n) {
    HashTable ht(100);
    int a, b, c, d;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if(ht.insert(sum, arr[i], arr[j], a, b, c, d)) {
                cout << "(" << a << ", " << b << ") and (" << c << ", " << d << ")" << endl;
                return;
            }
        }
    }
    
    cout << "No pairs found" << endl;
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    findPairs(arr1, 7);
    
    int arr2[] = {3, 4, 7, 1, 12, 9};
    findPairs(arr2, 6);
    
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    findPairs(arr3, 7);
    
    return 0;
}
