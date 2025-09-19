/*
Implement another function sumNonTail(int n) that calculates the same sum
using non-tail recursion. This function should perform an operation (e.g., addition) after
the recursive call returns. Compare the two implementations and explain the difference
in their call stacks.
*/

#include <iostream>
using namespace std;

int sumNonTail(int n) {
    if(n==0){
        return n;
    }
    else {
        return n + sumNonTail(n-1);
    }
     
}

int main() {
    cout << "Enter a number:" ;
    int n;
    cin >> n;
    cout << "Sum untill N: " << sumNonTail(n);
    
    return 0;
    
}
