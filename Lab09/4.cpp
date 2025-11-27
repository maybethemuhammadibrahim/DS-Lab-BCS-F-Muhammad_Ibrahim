#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;
};

class AVLTree {
public:
    Node* root;

    AVLTree() { root = NULL; }

    int getHeight(Node* n) {
        if (!n) return 0;
        return n->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* create(int data) {
        Node* n = new Node();
        n->data = data;
        n->left = n->right = NULL;
        n->height = 1;
        return n;
    }

    Node* rRot(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    Node* lRot(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    int getBal(Node* n) {
        if (!n) return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    Node* insert(Node* node, int data) {
        if (!node) return create(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int bal = getBal(node);

        if (bal > 1 && data < node->left->data)
            return rRot(node);
        if (bal < -1 && data > node->right->data)
            return lRot(node);
        if (bal > 1 && data > node->left->data) {
            node->left = lRot(node->left);
            return rRot(node);
        }
        if (bal < -1 && data < node->right->data) {
            node->right = rRot(node->right);
            return lRot(node);
        }
        return node;
    }

    void preOrder(Node* root) {
        if (root) {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void findKthSmallest(Node* node, int& k) {
        if (!node) return;
        findKthSmallest(node->left, k);
        k--;
        if (k == 0) cout << "Kth Smallest: " << node->data << endl;
        findKthSmallest(node->right, k);
    }

    void findKthLargest(Node* node, int& k) {
        if (!node) return;
        findKthLargest(node->right, k);
        k--;
        if (k == 0) cout << "Kth Largest: " << node->data << endl;
        findKthLargest(node->left, k);
    }
};

int main() {
    AVLTree t;
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 5);
    t.root = t.insert(t.root, 15);
    t.root = t.insert(t.root, 3);
    t.root = t.insert(t.root, 7);
    t.root = t.insert(t.root, 12);

    cout << "PreOrder:";
    t.preOrder(t.root);
    cout << endl;

    int k = 2; 
    int tempK = k;
    t.findKthSmallest(t.root, tempK);
    
    tempK = k; 
    t.findKthLargest(t.root, tempK);

    
        cout << "Left height:" << t.getHeight(t.root->left) << endl;
        cout << "Right height:" << t.getHeight(t.root->right) << endl;
    

    return 0;
}