/*
Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly.
*/

#include <iostream>
using namespace std;

void printFunctionA(int n) {
    if (n == 0) {
        cout << "0" << endl;
        return;
    }
    else {
        cout << n << endl;
        printFunctionA(n-1);
    }
}


int main() {
    cout << "Enter a number:" ;
    int n;
    cin >> n;
    cout << "Counting till 0: " << endl;
    printFunctionA(n);
    return 0;
    
}
