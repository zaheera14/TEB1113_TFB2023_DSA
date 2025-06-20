/*
id: 22011059
name: noor zaheera
group: g3
lab: L3
*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node *next_ptr;

    Node(string name, Node *next_ptr = nullptr)
    { // Constructor with default nullptr
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList(Node *head = nullptr)
    { // Constructor takes Node* and initializes tail
        this->head = head;
        this->tail = head;
        if (head)
            head->next_ptr = nullptr;
    }

    void add_element(Node *node)
    {
        if (!node)
            return; // Check for null pointer

        node->next_ptr = nullptr; // Set new node's next to nullptr

        if (!head)
        { // If list is empty
            head = node;
            tail = node;
        }
        else
        {
            tail->next_ptr = node; // Link current tail to new node
            tail = node;           // Update tail to new node
            tail->next_ptr = head;
        }
    }

    void display_list()
    {
        Node *current = head;
        
        do{
            cout << current->name <<" -> ";
            current = current->next_ptr;
        }
        while (current != head);
        
        cout << current->name << endl;
    }


    // Getter for head to allow memory cleanup in main
    Node *get_head() const
    {
        return head;
    }
};

int main() {
    cout << "Singly Linked List" << endl;
    // Create nodes dynamically
    Node *node1 = new Node("Zaza");
    Node *node2 = new Node("Zizi");
    Node *node3 = new Node("Zuzu");

    // Create linked list and add nodes
    LinkedList linkedlst(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    // Display the list
    linkedlst.display_list();

    return 0;
}