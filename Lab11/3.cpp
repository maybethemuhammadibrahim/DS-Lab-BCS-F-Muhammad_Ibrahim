#include <iostream>
#include <list>
using namespace std;
#define TABLE_SIZE 10

struct Record
{
    string data;
    int id;

    Record(string data, int id) : data(data), id(id) {}
};

class Hash
{
    list<Record> records[TABLE_SIZE];

    int hash(int key)
    {
        return key % 10;
    }

public:
    Hash()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            records[i].clear();
        }
    }

    void insert(int id, string data)
    {
        int index = hash(id);
        for(Record& r: records[index]) {
            if(r.id == id) {
                r.data = data;
                return;
            }
        }
        Record *n = new Record(data, id);
        records[index].push_front(*n);
    }

    Record search(int id) {
        int index = hash(id);
        for(Record& r: records[index]) {
            if(r.id == id) {
                return r;
            }
        }
    }

    void remove(int id) {
    int index = hash(id);

    auto it = records[index].begin();

    while (it != records[index].end()) {
        if (it->id == id) {
            it = records[index].erase(it); 
            
            return;
        } else {
            it++;
        }
    }
}

    void display()
    {
        cout << "Printing the Hash Table" << endl;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << "|";
            if (!records[i].empty())
            {
                for (const Record &r : records[i])
                {
                    cout << r.data << "->";
                }
                cout << endl;
            }
            else {
                cout << "___empty___" << endl;
            }
        }
    }
};

int main()
{
    Hash table;
    table.insert(1, "data1");
    table.insert(1, "data5");
    table.insert(2, "data2");
    table.insert(3, "data3");
    table.insert(4, "data4");
    cout << "Initial:" << endl;
    table.display();
    table.remove(4);
    cout << "\n\n\nAfter removing at key 4" << endl;
    table.display();
}
