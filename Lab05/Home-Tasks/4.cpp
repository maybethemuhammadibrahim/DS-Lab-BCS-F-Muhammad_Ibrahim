#include <iostream>
using namespace std;
/*Write a C++ program that implements the Ackermann function, which is a classic example of
nested recursion. The function ackermann(int m, int n) is defined as:
● If m=0, return n+1.
● If m>0 and n=0, return ackermann(m-1, 1).
● If m>0 and n>0, return ackermann(m-1, ackermann(m, n-1)).
This task requires you to trace the execution and understand how one recursive call is a
parameter to another.*/

int ackermann(int m, int n) {
    if(m == 0) {
        return n+1;
    }
    else if(m>0 && n==0) {
        return ackermann(m-1, 1);
    }
    else if(m>0 && n>0) {
        return ackermann(m-1, ackermann(m, n-1));
    }
    else {
        return -1;
    }
}

int main() {
    int m, n;
    cout << "give m and n for Ackermann:" << endl;
    cin >> m >> n;
    int result = ackermann(m, n);
    cout << "answer is: " << result << endl;
    return 0;
}
