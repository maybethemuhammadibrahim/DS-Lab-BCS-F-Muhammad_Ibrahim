#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    Node *insert(Node *root, int data)
    {
        if (!root)
            return new Node(data);

        if (data > root->data)
            root->right = insert(root->right, data);
        else if (data < root->data)
            root->left = insert(root->left, data);

        return root;
    }

    bool search(Node *root, int data)
    {
        if (!root)  
            return false;
            
        if (root->data == data)
            return true;

        if (data > root->data)
            return search(root->right, data);
        else  
            return search(root->left, data);
    }

public:
    BST() : root(nullptr) {}

    Node* getHead() { return root; }

    void insert(int data) {
        root = insert(root, data);
    }

    void search(int data) {
        bool found = search(root, data);  
        if(found) 
            cout << "Data Found!" << endl;
        else{
            cout << "Not Found!(Inserting)" << endl;
            insert(data);

        } 
            
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }



};
int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    
    int value;
    cout << "Enter value to search: ";
    cin >> value;
    tree.search(value);

    cout << "Tree: ";
    tree.inorder(tree.getHead());
    
    return 0;
}