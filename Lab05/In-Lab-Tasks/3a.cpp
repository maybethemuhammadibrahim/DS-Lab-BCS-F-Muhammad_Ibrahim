/*
Implement a C++ function sumTail(int n, int total) that calculates the sum
of numbers from 1 to n using tail recursion. The recursive call should be the last
operation in the function.
*/

#include <iostream>
using namespace std;

int sumTail(int n, int total) {
    if(n==0){
        return total;
    }
    else {
        total += n;
        return sumTail(n-1, total);
    }
     
}

int main() {
    cout << "Enter a number:" ;
    int n;
    cin >> n;
    cout << "Sum untill N: " << sumTail(n, 0);
    
    return 0;
    
}
