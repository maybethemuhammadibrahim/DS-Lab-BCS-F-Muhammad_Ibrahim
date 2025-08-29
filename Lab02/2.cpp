/*
Task #2:
Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
=> Rows represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form.
*/
#include <iostream>
using namespace std;

void displayArr(int** arr, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }
}

int main() {
    int **benches;
    int temp, noOfBenches, noOfColumns; 
    //benches = rows
    //coloumns = coloumns
  
    cout << "Enter the number of benches(rows): " ;
    cin >> noOfBenches;

    cout << "Enter the number of seats in each bench(columns): " ;
    cin >> noOfColumns;

    benches = new int*[noOfBenches];
    for(int i = 0; i < noOfBenches; i++) {
        benches[i] = new int[noOfColumns];
    }
    cout << "Mem allocated" << endl;


    for(int i = 0 ; i < noOfBenches; i++){
        for(int j = 0; j <noOfColumns; j++) {
            benches[i][j] = 0;
        }
    }
    cout << "Initialized the seats to 0(unoccupied)" << endl;
    displayArr(benches,noOfBenches,noOfColumns);

    cout << "Enter availability of seat(0 for available, 1 for occupied)" << endl;
    for(int i = 0 ; i < noOfBenches; i++){
        for(int j = 0; j <noOfColumns; j++) {
            cout << "at " << i+1 << "," << j+1 << " : ";
            cin >> temp;
            //condition to verify 1 or 0
            if(temp == 1 || temp == 0) {
                benches[i][j] = temp;
            }
            else {
                cout << "Only enter value between 1 and 0" << endl;
                j--;
            }
        }
    }
    cout << "Final Seating Chart" << endl;
    displayArr(benches,noOfBenches,noOfColumns);

    for(int i = 0; i < noOfBenches; i++) {
        delete[] benches[i];
    }
    delete[] benches;
    cout << "Memory freed" << endl;
    // displayArr(benches,noOfBenches,noOfColumns);

}
