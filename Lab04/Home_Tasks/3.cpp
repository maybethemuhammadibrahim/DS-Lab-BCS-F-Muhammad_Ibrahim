#include <iostream>
using namespace std;

class IntArray {
    private:
    int *data;
    int size;
    public:
    IntArray(int size=0) : size(size) {
        if(size > 0){
            data = new int[size];
        } 
        else{
            data = nullptr;
        }
    }
    
    void fill() {
        if(size <= 0){
            cout << "array size not set" << endl;
            return;
        }
        for(int i = 0; i <size; i++) {
            cin >> data[i];
        }
    }

    void display() {
        if(size <= 0){
            cout << "array empty" << endl;
            return;
        }
        cout << "array: ";
        for(int i = 0; i < size; i++){
            cout << data[i] << ", ";
        }
        cout << endl;
    }
    
    void selectionSort() {
        if(size <= 0){
            return;
        }

        for(int i = 0; i < size-1; i++){
            int minIndex = i;

            for(int j = i + 1; j<size; j++) {
                if(data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }

            if(minIndex != i) {
                int temp = data[i];
                data[i] = data[minIndex];
                data[minIndex] = temp;
            }
        }
    }
    
    ~IntArray() {
        delete [] data;
    }
};

int main() {
    int n;
    cout << "enter size:" << endl;
    cin >> n;
    
    IntArray arr(n);
    cout << "enter " << n << " numbers:" << endl;
    arr.fill();
    
    cout << "before sort:" << endl;
    arr.display();
    
    
    cout << "sorting with insertion sort..." << endl;
    arr.selectionSort();
    
    cout << "sorted array:" << endl;
    arr.display();
    
    return 0;
}

