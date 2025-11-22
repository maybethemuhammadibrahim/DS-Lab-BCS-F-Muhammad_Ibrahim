
#include <iostream>
using namespace std;
#define Table_size 15

class SRecord {
    private:
    int id;
    string name;
    public:
    SRecord(int id = -1, string record = "") : id(id), name(record) {}

    int getID() {return id;}
    string getName(){return name;}
    void setID(int id) {this->id = id;}
    void setName(string name) {this->name = name;}

};

class HTable {
    SRecord records[Table_size];
    bool occupied[Table_size] = {false};

    int hash(int id) {
        return id % Table_size;
    }

    public:
    HTable() {
    }

    void insert(int id, string name) {
        int index = hash(id);
        int sIndex = index;
        int i = 1;

        while(occupied[index] == true) {
            if(records[index].getID() == id) {
                records[index].setName(name);
                return ;
            }
            index = (sIndex + i^2) % Table_size;
            i++;
            if(index == sIndex) {
                cout << "Hash Table Full" << endl;
                return ;
            }
        }
        if(occupied[index] == false) {
            occupied[index] = true;
            records[index].setID(id);
            records[index].setName(name);
        }
    }

    void search(int id) {
        int index = hash(id);
        int sIndex = index;
        int i = 1;
        while(occupied[index] == true) {
            if(records[index].getID() == id) {
                cout << "Student: " << records[index].getName() << " (at index = " << index << endl;
                return ;
            }
            
                index = (sIndex + i^2) % Table_size;
                i++;
                if(index == sIndex) {
                    cout << "Record Not Found" << endl;
                    return ;
                }
            

        }
    }

    void display() {
        for(int i = 0; i < Table_size; i++) {
            if(occupied[i])
                cout << records[i].getID() << " " << records[i].getName() << endl;
        }
    }
};

int main() {
    HTable table;

    table.insert(1, "Ibrahim");
    table.insert(1, "abc");//update ibrahim
    table.insert(2, "bbb");
    table.insert(3, "ccc");
    // table.display();
    table.search(1);
}
