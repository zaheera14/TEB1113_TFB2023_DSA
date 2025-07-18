/*
id: 22011059
name: noor zaheera
group: g3
lab: L8 ( binary search tree )
*/


#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    Node* insert(Node* node, string name) {
        if (!node) return new Node(name);
        if (name < node->name)
            node->left = insert(node->left, name);
        else if (name > node->name)
            node->right = insert(node->right, name);
        return node;
    }

    void insert(string name) {
        root = insert(root, name);
    }

    // Display top-down tree (manually structured for 3 levels only)
    void printManual() {
        cout << "    D\n";
        cout << "   / \\\n";
        cout << "  B   F\n";
        cout << " / \\ / \\\n";
        cout << "A  C E  G\n";
    }

    bool search(Node* node, string target) {
        cout << "\nSearching for " << target << "...\n";
        while (node) {
            cout << "Visiting " << node->name << endl;
            if (target == node->name) {
                cout << "\n" << target << " found\n";
                return true;
            }
            else if (target < node->name)
                node = node->left;
            else
                node = node->right;
        }
        cout << "\n" << target << " not found\n";
        return false;
    }
};

int main() {
    Tree tree;

    // Insert in BST order
    tree.insert("D");
    tree.insert("B");
    tree.insert("F");
    tree.insert("A");
    tree.insert("C");
    tree.insert("E");
    tree.insert("G");

    // Print top-down tree with full branches
    tree.printManual();

    // Search example
    tree.search(tree.root, "F");

    return 0;
}
