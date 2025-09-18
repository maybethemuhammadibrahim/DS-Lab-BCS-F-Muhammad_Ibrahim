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
    
    int linearSearch(int target) {
        for(int i = 0; i < size; i++) {
            if(data[i] == target){
                return i;
            }
        }
        return -1;
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
    
    ~IntArray() {
        delete []data;
    }
};

int main() {
    int n;
    cout << "enter array size:" << endl;
    cin >> n;

    IntArray arr(n);
    cout << "enter " << n << " integers:" << endl;
    arr.fill();
    
    cout << "enter target:" << endl;
    int target;
    cin >> target;
    
    cout << "doing linear search..." << endl;
    int idx = arr.linearSearch(target);
    
    if(idx == -1) {
        cout << "element not found in array" << endl;
    } 
    else {
        cout << "found at index " << idx << endl;
    }
    
    return 0;
}