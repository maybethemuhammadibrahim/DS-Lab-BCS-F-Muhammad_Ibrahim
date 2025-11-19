#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <string>

using namespace std;

int getRandom(int upper)
{
    return rand() % (upper + 1);
}

class Combatant
{
private:
    int id;
    string name;
    float hp;
    float ap;

public:
    Combatant(int id = -1, string name = "0", float ap = 0) : id(id), name(name), hp(100), ap(ap) {}

    int getID() { return id; }
    float getHp() { return hp; }
    float getAp() { return ap; }
    void setHp(float hp) { this->hp = hp; }

    void display()
    {
        cout << "ID: " << id
             << " | Name: " << name
             << " | HP: " << hp
             << " | AP: " << ap << endl;
    }
};

struct Node
{
    Combatant data;
    Node *left;
    Node *right;

    Node(Combatant data) : data(data), left(nullptr), right(nullptr) {} // Fixed: removed default =0
};

class BST
{
private:
    Node *root;

    Node *insert(Node *root, Combatant data)
    {
        if (!root)
            return new Node(data);

        if (data.getID() > root->data.getID())
            root->right = insert(root->right, data);
        else if (data.getID() < root->data.getID())
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
        if (data > root->data.getID())
            root->right = deleteN(root->right, data);
        else if (data < root->data.getID())
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
                root->right = deleteN(root->right, temp->data.getID());
            }
        }
        return root;
    }

    bool search(Node *root, int data)
    {
        if (!root) 
            return false;
            
        if (root->data.getID() == data)
            return true;

        if (data > root->data.getID())
            return search(root->right, data);
        else 
            return search(root->left, data);
    }

public:
    BST() : root(nullptr) {}

    Node *getRoot() { return root; } 

    Node *minimumInTree(Node *start) 
    {
        Node *current = start;
        while (current && current->left)
        {
            current = current->left;
        }
        return current;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    void insert(Combatant data)
    {
        root = insert(root, data);
    }

    void deleteN(int data)
    {
        root = deleteN(root, data);
    }

    bool search(int data) 
    {
        return search(root, data);
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        root->data.display();
        inorder(root->right);
    }
};

class GameManager
{
    BST player;
    BST opponents;
    int roundNo;

public:
    GameManager() : roundNo(0) {

        //auto hereos and enemys
        for(int i = 0; i < 5; i++) {
            string name = "Hero_" + to_string(i + 1);
            float ap = 10 + getRandom(4);
            Combatant hero(i + 1, name, ap);
            player.insert(hero);
        }

        for(int i = 0; i < 5; i++) {
            string name = "Enemy_" + to_string(i + 1);
            float ap = 7 + getRandom(4);
            Combatant enemy(100 + i, name, ap);
            opponents.insert(enemy);
        }
    }

    void conductGame()
    {
        Node *attacker, *defender;
        bool isPlayerTurn;

        while (!player.isEmpty() && !opponents.isEmpty())
        {
            roundNo++;
            
        
            if (roundNo % 2 == 0)
            {
                attacker = opponents.minimumInTree(opponents.getRoot());
                defender = player.minimumInTree(player.getRoot());
                isPlayerTurn = false;
            }
            else
            {
                attacker = player.minimumInTree(player.getRoot());
                defender = opponents.minimumInTree(opponents.getRoot());
                isPlayerTurn = true;
            }

            float damage = attacker->data.getAp() + getRandom(4);
            defender->data.setHp(defender->data.getHp() - damage);

            cout << "\n--- Round " << roundNo << " ---" << endl;
            cout << "Attacker: ";
            if (isPlayerTurn)
                cout << "Player";
            else
                cout << "Opponent";
            cout << endl;
            cout << "Damage Dealt: " << damage << endl;
            
            if (defender->data.getHp() <= 0)
            {
                cout << "Defeated: ";
                defender->data.display();
                
                if (isPlayerTurn)
                {
                    opponents.deleteN(defender->data.getID());
                }
                else
                {
                    player.deleteN(defender->data.getID());
                }
            }
            else
            {
                cout << "Defender HP remaining: " << defender->data.getHp() << endl;
            }

    
            cout << "\nPlayer Team:" << endl;
            player.inorder(player.getRoot());
            
            cout << "\nOpponent Team:" << endl;
            opponents.inorder(opponents.getRoot());
        }

        cout << "\n=== GAME OVER ===" << endl;
        if (player.isEmpty())
        {
            cout << "Opponents Win!!" << endl;
        }
        else
        {
            cout << "Players Win!!" << endl;
        }
    }
};

int main()
{
    srand(time(nullptr));
    GameManager game;
    game.conductGame();
    return 0;
}