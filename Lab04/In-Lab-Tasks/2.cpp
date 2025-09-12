#include <iostream>
using namespace std;

//assuming the array will be sorted
//assuming the data in array will be two digit ints


void insert(int *&arr, int &size, int insertIndex, int insertValue) {
    int *temp = new int[size + 1];
    for (int i = 0; i < insertIndex; i++) {
        temp[i] = arr[i];
    }
    temp[insertIndex] = insertValue;
    for (int i = insertIndex; i < size; i++) {
        temp[i + 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size++;  
}

int binarySearch(int *&arr, int &size, int lower, int higher, int valueToSearch) {
    int mid;
    while (lower <= higher) {
        mid = lower + (higher - lower) / 2;
        if (arr[mid] == valueToSearch) {
            return mid;
        }
        else if (arr[mid] < valueToSearch) {
            lower = mid + 1;
        }
        else {
            higher = mid - 1;
        }
    }
    // cout << "Mid is: " << mid;
    insert(arr, size, mid+1, valueToSearch);
    return -1;
}

int main() {
    int *arr, size, lastTwoRollNoDigits = 49;
    cout << "Enter size:";
    cin >> size;
    arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter Element at " << i << ": ";
        cin >> arr[i];
    }

    int result = binarySearch(arr, size, 0, size - 1, lastTwoRollNoDigits);
    cout << "Binary Search Result (-1 indicates index not found): " << result << endl;

    for (int i = 0; i < size; i++) {
        cout << "Element at: " << arr[i] << endl;
    }

    delete[] arr;
    return 0;
}
