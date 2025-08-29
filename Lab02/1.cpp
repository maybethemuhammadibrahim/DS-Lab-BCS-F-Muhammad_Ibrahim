/*
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly
*/
#include <iostream>
using namespace std;

void displayArr(int* arr, int noOfElements) {
    for(int i = 0; i < noOfElements; i++) {
        cout << i+1 << " : "<< arr[i] << endl;
    }
}

int main() {
    int *arr;
    int noOfElements;
    cout << "Enter the number of elements: " ;
    cin >> noOfElements;

    arr = new int[noOfElements];
    for(int i = 0; i < noOfElements; i++) {
        arr[i] = 0;
    }
    cout << "Initialized all elements to 0" << endl;
    displayArr(arr, noOfElements);

    for(int i = 0; i < noOfElements; i++) {
        cout << "Enter element at position(0 to skip) " << i+1 << " : ";
        cin >> arr[i];
    }
    displayArr(arr, noOfElements);

    delete[] arr;
    cout << "Memory freed" << endl;

    displayArr(arr, noOfElements);
    
}
