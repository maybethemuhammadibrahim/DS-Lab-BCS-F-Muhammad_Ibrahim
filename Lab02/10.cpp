/*
design a program that maintains library book records using dynamic arrays.
=> each row represents a category (e.g., fiction, science, history).
=> each category has a different number of books (use a jagged array).
=> store book ids dynamically and allow the user to search for a given book id.
=> print whether the book is available and in which category.
*/
#include <iostream>
using namespace std;

class book {
    string id;
    public:
    book(string id = "") : id(id) {}
    
    void setid(string newid) {
        id = newid;
    }
    
    string getid() {
        return id;
    }
};

class category {
    private:
    string name;
    book *books;
    int noofbooks;
    
    public:
    category() {
        name = "";
        books = nullptr;
        noofbooks = 0;
    }
    
    string getname() {
        return name;
    }
    
    void allocate(int index) {
        string tempstring;
        
        cout << "enter name of category at (" << index << ") index: ";
        cin >> name;
        cout << "enter number of books in " << name << " : ";
        cin >> noofbooks;
        books = new book[noofbooks];
        
        cout << "enter book ids for " << name << " category:" << endl;
        for(int i = 0; i < noofbooks; i++) {
            cout << "enter book id for book " << i+1 << ": ";
            cin >> tempstring;
            books[i].setid(tempstring);
        }
    }
    
    bool searchbook(string searchid) {
        for(int i = 0; i < noofbooks; i++) {
            if(books[i].getid() == searchid) {
                return true;
            }
        }
        return false;
    }
    
    void display() {
        for(int i = 0; i < noofbooks; i++) {
            cout << "[" << books[i].getid() << "] ,";
        }
    }
    
    ~category() {
        delete[] books;
        books = nullptr;
    }
};

int main() {
    category *categories;
    int noofcategories;
    string searchid;
    
    cout << "enter number of categories: ";
    cin >> noofcategories;
    
    categories = new category[noofcategories];
    
    for(int i = 0; i < noofcategories; i++) {
        categories[i].allocate(i+1);
    }

    //jagged array implementation display
    cout << "\nprinting all books in library:" << endl;
    for(int i = 0; i < noofcategories; i++) {
        cout << categories[i].getname() << " category: ";
        categories[i].display();
        cout << endl;
    }
    
    cout << "\nenter book id to search: ";
    cin >> searchid;
    

    //book searching
    bool found = false;
    for(int i = 0; i < noofcategories; i++) {
        if(categories[i].searchbook(searchid)) {
            cout << "book found in " << categories[i].getname() << " category" << endl;
            found = true;
            break;
        }
    }
    
    if(!found) {
        cout << "book not found in any category" << endl;
    }
    
    delete[] categories;
    
    return 0;
}
