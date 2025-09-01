/*Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=>
Demonstrate the class by storing marks of 5 students and printing them safely without
direct pointer manipulation.*/
/*Used Prettier(Vs Code extention for formatting code)*/

#include <iostream>
using namespace std;

class SafePointer
{
private:
    int *p = nullptr;

public:
    SafePointer(int val = 0)//if value passed at initialization
    {
        p = new int;
        *p = val;
    }

    void setValue(int val)
    {
        *p = val;
    }

    int getValue()
    {
        return *p;
    }

    void release()
    {
        delete p;
    }

    ~SafePointer()
    {
        delete p;
    }
};

int main()
{
    SafePointer students[5] = {20, 30, 40, 50, 60};
    
    students[3].setValue(100);
    
    for(int i = 0; i < 5 ; i++) {
        cout << "Marks for student " << i + 1 << " are :" << students[i].getValue() << endl;
    }

    for(int i = 0; i < 5 ; i++) {
        students[i].release();
    }
    
}
