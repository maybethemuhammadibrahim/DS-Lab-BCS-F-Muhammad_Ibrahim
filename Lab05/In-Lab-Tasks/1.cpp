/*
Write a recursive C++ function calculateFactorial(int n) that computes the factorial
of a given integer n . The function should have a base condition to stop the recursion when n is
0 or 1, and should call itself with a smaller value of n (e.g., n-1) to solve the problem.
*/

#include <iostream>
using namespace std;

int calculateFactorial(int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return n * calculateFactorial(n-1);
    }
}

int main() {
    cout << "Enter the number to find Factorial of:" ;
    int n;
    cin >> n;
    cout << "Factorial is: " << calculateFactorial(n);
    return 0;
    
}
