#include <iostream>
using namespace std;

void swap(int& src, int& dest){
    int temp = src;
    src = dest;
    dest = temp;
}

class maxHeap {
private:
    int heap[100];
    int size;

    int parent(int index) {
        return (index - 1) / 2;
    }
    int left(int index) {
        return (2*index) + 1;
    }
    int right(int index) {
        return (2*index) + 2;
    }

public:
    maxHeap() { size = 0; }

    void heapify_up(int index) {
        while(index != 0 && heap[index] > heap[parent(index)]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }   

    void heapify_down(int index) {
        int largest = index;
        int l = left(index);
        int r = right(index);

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;   

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify_down(largest);
        }
    }

    void insert(int val) {
        if(size >= 100) {
            cout << "Heap Overflow" << endl;
            return;
        } 
        heap[size] = val;
        heapify_up(size);
        size++;
    }

    void deleteRoot() {
        if (size <= 0) {    
            cout << "Heap UnderFlow!" << endl;
            return;
        }
        cout << "Deleted Item: " << heap[0] << endl;
        swap(heap[0], heap[size-1]);
        size--;
        heapify_down(0);
    }

    bool checkMaxHeap() {
    for(int i = 0; i <= size - 2 ; i++) {  
        int l = left(i);
        int r = right(i);
        if(l < size && heap[i] < heap[l])
            return false;
        if(r < size && heap[i] < heap[r])
            return false;
    }

    return true;
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << heap[i] << ", ";
        }
    }
};

int main() {
    maxHeap h;

    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    h.display();
    cout << endl;
    cout << "Is Heap?(0-false, 1-true): " << h.checkMaxHeap() << endl;

    return 0;
}
