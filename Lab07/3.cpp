#include <iostream>
#include <string>
using namespace std;

class Runner {
private:
    string name;
    int time; 

public:
    Runner(string name = "", int time = 0) : name(name), time(time) {}

    string getName() { return name; }
    int getTime() { return time; }  
    void setName(string name) { this->name = name; }
    void setTime(int t) { this->time = t; }
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner* L = new Runner[n1];
    Runner* R = new Runner[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].getTime() <= R[j].getTime()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int NUM_RUNNERS = 10;  
    Runner runners[NUM_RUNNERS];
    string name;
    int time;

    
    cout << "Enter details for 10 participants:\n";

    for(int i = 0; i < NUM_RUNNERS; i++) {
        cout << "Runner " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter finish time (int): ";
        cin >> time;
        
        runners[i].setName(name);
        runners[i].setTime(time);
        cout << endl;
    }

    mergeSort(runners, 0, NUM_RUNNERS - 1);  

    cout << "TOP 5 FASTEST RUNNERS\n";
    for(int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].getName() << " - " << runners[i].getTime() << " seconds" << endl;
    }

    return 0;
}
