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

    Node *minimumInTree(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

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

    Node *deleteN(Node *root, int data)
    {
        if (!root)
        {
            cout << "Data does not exist(returning)!" << endl;
            return root;
        }
        if (data > root->data)
            root->right = deleteN(root->right, data);
        else if (data < root->data)
            root->left = deleteN(root->left, data);
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
                root->right = deleteN(root->right, temp->data);
            }
        }
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

    void deleteN(int data) {
        root = deleteN(root, data);
    }

    void search(int data) {
        bool found = search(root, data);  
        if(found) 
            cout << "Data Found!" << endl;
        else 
            cout << "Not Found!" << endl;
    }
    
    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    BST tree;                   
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.inorder(tree.getHead());            
    cout << endl;

    cout << "Preorder: ";
    tree.preorder(tree.getHead());
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(tree.getHead());
    cout << endl;

    cout << "\nSearching for 40: ";
    tree.search(40);
    
    cout << "Searching for 100: ";
    tree.search(100);

    tree.deleteN(20);
    tree.deleteN(70);

    cout << "After deletion (Inorder): ";
    tree.inorder(tree.getHead());
    cout << endl;

    return 0;
}
