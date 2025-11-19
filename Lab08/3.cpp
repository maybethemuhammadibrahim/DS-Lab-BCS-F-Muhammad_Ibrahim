#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float score;

public:
    Student(string name = "", int roll = -2, float score = -1) : name(name), roll(roll), score(score) {}
    string getName() const {
        return name;
    }

    int getRoll() const {
        return roll;
    }

    float getScore() const {
        return score;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setRoll(int newRoll) {
        roll = newRoll;
    }

    void setScore(float newScore) {
        if(newScore >= 0 && newScore <= 100) { 
            score = newScore;
        } else {
            cout << "Invalid score! Score should be between 0 and 100." << endl;
        }
    }
    
    void display() const {
        cout << name << " (Roll: " << roll << ", Score: " << score << ")" << endl;
    }
};

struct Node
{
    Student data;
    Node *left;
    Node *right;

    Node(Student data) : data(data), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    Node *minimumInTree(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

    Node *insert(Node *root, Student data)
    {
        if (!root)
            return new Node(data);

        if (data.getScore() > root->data.getScore())
            root->right = insert(root->right, data);
        else if (data.getScore() < root->data.getScore())
            root->left = insert(root->left, data);

        return root;
    }

    Node *deleteN(Node *root, float score)
    {
        if (!root)
        {
            return root;
        }
        if (score > root->data.getScore())
            root->right = deleteN(root->right, score);
        else if (score < root->data.getScore())
            root->left = deleteN(root->left, score);
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            else if (!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = minimumInTree(root->right);
                root->data = temp->data;
                root->right = deleteN(root->right, temp->data.getScore());
            }
        }
        return root;
    }

    bool search(Node *root, string data)
    {
        if (!root)  
            return false;
            
        if (root->data.getName() == data)
            return true;

        
        return search(root->left, data) || search(root->right, data);
    }

    void deleteLowScorers(Node* node, float threshold) {
        if (!node) return;
        
        
        deleteLowScorers(node->left, threshold);
        deleteLowScorers(node->right, threshold);
        
        
        if (node->data.getScore() < threshold) {
            root = deleteN(root, node->data.getScore());
        }
    }

public:
    BST() : root(nullptr) {}

    Node* getHead() { return root; }

    void insert(Student data) {
        root = insert(root, data);
    }

    void deleteN(float score) {
        root = deleteN(root, score);
    }

    void search(string data) {
        bool found = search(root, data);  
        if(found) 
            cout << "Student Found!" << endl;
        else 
            cout << "Student Not Found!" << endl;
    }
    
    Node* getMax(Node* node) {
        if (!node) return nullptr;
        while(node && node->right) {
            node = node->right;
        }
        return node;
    }

    void deleteLowScorers(float threshold) {
        deleteLowScorers(root, threshold);
    }

    void displayInorder(Node* node) {
        if (!node) return;
        displayInorder(node->left);
        node->data.display();
        displayInorder(node->right);
    }
};

int main() {
    BST studentTree;
    
    //student record from gpt
    studentTree.insert(Student("Alice Johnson", 101, 85.5));
    studentTree.insert(Student("Bob Smith", 102, 92.0));
    studentTree.insert(Student("Carol Davis", 103, 78.5));
    studentTree.insert(Student("David Wilson", 104, 8.5));
    studentTree.insert(Student("Eva Brown", 105, 95.0));
    studentTree.insert(Student("Frank Miller", 106, 5.5));
    
    cout << "All Students:" << endl;
    studentTree.displayInorder(studentTree.getHead());
    
    cout << "\nSearching students:" << endl;
    studentTree.search("Alice Johnson");
    studentTree.search("Unknown Student");
    
    cout << "\nDeleting students with score less than 10:" << endl;
    studentTree.deleteLowScorers(10);
    
    cout << "\nStudent with maximum score:" << endl;
    Node *maxStudent = studentTree.getMax(studentTree.getHead());
    if (maxStudent) {
        maxStudent->data.display();
    } else {
        cout << "No students found!" << endl;
    }
    
    cout << "\nRemaining Students:" << endl;
    studentTree.displayInorder(studentTree.getHead());
    
    return 0;
}