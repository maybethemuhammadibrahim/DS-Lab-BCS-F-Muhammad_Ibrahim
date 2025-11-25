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
        swap(heap[0], heap[size-1]);
        size--;
        heapify_down(0);
    }

    int getRoot() {
        if(size > 0)
            return heap[0];
        return -1;
    }

    void update_key(int i, int new_val) {
        int old_val = heap[i];
        heap[i] = new_val;
        if (new_val > old_val) {
            heapify_up(i);
        } else if (new_val < old_val) {
            heapify_down(i);
        }
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << heap[i] << endl;
        }
    }

    int kthLargest(int arr[], int n, int k) {
        for(int i = 0; i < n; i++) {
            insert(arr[i]);
        }
        for(int i = 0; i < k-1; i++) {
            deleteRoot();
        }
        return getRoot();
    }
};

int main() {
    maxHeap h;
    
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int arr2[] = {12, 3, 5, 7, 19};
    
    cout << h.kthLargest(arr1, 7, 3) << endl;
    
    maxHeap h2;
    cout << h2.kthLargest(arr2, 5, 2) << endl;

    return 0;
}
