
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
    
    void bubbleSort() {
        if(size <= 1) {
            return;
        }

        int temp;
        bool swapped= true;


        for(int pass = 0; pass < size-1 && swapped; pass++) {
            swapped = false;
            for(int j = 0; j < size-1 - pass; j++) {
                if(data[j] > data[j+1]){
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                    swapped = true;
                }
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
    
    cout << "sorting with bubble sort..." << endl;
    arr.bubbleSort();
    
    cout << "after sort:" << endl;
    arr.display();
    
    return 0;
}

