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
    
    int interpolationSearch(int target) {
    if(size <= 0){
        return -1;
    }
    int low = 0;
    int high = size-1;
    
    while(low<=high && target>=data[low] && target<=data[high]){
        if(data[low] == data[high]) {
            if(data[low] == target) 
                return low;
            else 
                return -1;
        }
        
        int pos = low + ((target-data[low])*(high-low)) / (data[high]-data[low]);
        
        if(data[pos] == target){
            return pos;
        } 
        else if(data[pos] < target){
            low = pos + 1;
        } 
        else{
            high = pos - 1;
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
    cout << "enter " << n << " numbers(sorted pls):" << endl;
    arr.fill();
    
    cout << "array you gave:" << endl;
    arr.display();
    
    cout << "enter target:" << endl;
    int target;
    cin >> target;
    
    cout << "doing interpolation search..." << endl;
    int idx = arr.interpolationSearch(target);
    if(idx == -1){
        cout << "not found" << endl;
    } 
    else{
        cout << "found at index " << idx << endl;
    }
    
    return 0;
}