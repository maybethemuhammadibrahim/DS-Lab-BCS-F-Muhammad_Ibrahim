/*Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.
*/

#include <iostream>
using namespace std;

class Box
{
private:
    int *length, *width, *height;

public:
    Box(int l = 0, int b = 0, int h = 0)
    {
        length = new int;
        *length = l;

        width = new int;
        *width = b;

        height = new int;
        *height = h;
    }

    Box(const Box &other)
    {
        // since it is only a single int and not an array copying by derefrencing
        length = new int;
        width = new int;
        height = new int;

        *length = *other.length;
        *width = *other.width;
        *height = *other.height;
    }

    Box &operator=(const Box &other)
    {
        *length = *other.length;
        *width = *other.width;
        *height = *other.height;
        return *this;
    }

    ~Box()
    {
        delete length;
        delete width;
        delete height;
    }

    int getLength()
    {
        return *length;
    }

    int getWidth()
    {
        return *width;
    }

    int getHeight()
    {
        return *height;
    }

    void showDetails()
    {
        cout << "Width: " << *width << "\nHeight: " << *height << "\nlength: " << *length << endl;
        cout << endl;
    }
};

int main()
{
    Box *b1 = new Box(2, 3, 4);
    cout << "Created Box b1" << endl;
    b1->showDetails();

    Box b2(*b1);
    cout << "Created Box b2 as a copy of b1" << endl;
    b2.showDetails();

    delete b1;

    cout << "Deleted b1 and showing b2 again to demonstrate deep copy" << endl;
    b2.showDetails();
}
