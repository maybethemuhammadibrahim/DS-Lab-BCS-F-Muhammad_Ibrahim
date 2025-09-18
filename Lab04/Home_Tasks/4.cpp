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
    
    void insertionSort() {
        if(size <= 1){
            return;
        } 


        for(int i = 1; i<size; i++) {

            int key = data[i];
            int j = i-1;
            while(j>=0 && data[j]>key) {
                data[j+1] = data[j];
                j--;
            }

            data[j+1] = key;
        }
    }
    
    int binarySearch(int target) {
        int left = 0;
        int right = size - 1;

        while(left <= right){
            int mid = (left+(right - left))/2;
            if(data[mid] == target){
                return mid;
            }
            else if(data[mid] < target){
                left = mid + 1;
            } 
            else{
                right = mid - 1;
            }
        }
        return -1;
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
    arr.insertionSort();
    
    cout << "sorted array:" << endl;
    arr.display();
    
    cout << "enter target to find:" << endl;
    int target;
    cin >> target;
    
    cout << "doing binary search..." << endl;
    int idx = arr.binarySearch(target);
    if(idx==-1) {
        cout << "element not found" << endl;
    } else {
        cout << "found at index " << idx << endl;
    }
    
    return 0;
}

