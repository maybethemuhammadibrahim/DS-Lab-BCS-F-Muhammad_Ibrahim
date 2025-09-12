#include <iostream>
using namespace std;

int linearSearch(int* Arr, int size, int valueToSearch) {
    bool isFound = false;
    for(int i = 0; i < size; i++) {
        if(valueToSearch == Arr[i]) {
            isFound = true;
            cout << "Value Found at " << endl;
            return i;
        }
        else {
            isFound = false;
        }
    }
    if(!isFound) {
        cout << " Value Not Found " << endl;
        
    }
    return -1;
    
}


int main() {
    //hardcoded version
    // int arr[10] = {10,20,30,40,50,1,7,8,9,10};
    // int temp;
    // cout << "Enter value to search: ";
    // cin >> temp;
    // cout << "Linear Search Result(-1 indicates index not found): " << linearSearch(arr,10,temp) << endl;
    // return 0;

    int *arr, size, valueToSearch;
    cout << "Enter size:";
    cin >> size;
    arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter Element at " << i << ": ";
        cin >> arr[i];
    }

    cout << "Enter value to search: ";
    cin >> valueToSearch;

    int result = linearSearch(arr, size, valueToSearch);
    cout << "Linear Search Result (-1 indicates index not found): " << result << endl;

    delete[] arr;
    return 0;
}
