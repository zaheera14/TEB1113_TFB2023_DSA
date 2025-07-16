/*
id: 22011059
name: noor zaheera
group: g3
lab: L5 
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
    {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack(Node *top = nullptr)
    {
        this->top = top;
        if (top)
            top->next_ptr = nullptr;
    }

    void push(Node *node)
    {
        if (!node)
            return;

        node->next_ptr = top;
        top = node;
    }

    void pop()
    {
        if (!top)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = top;
        top = top->next_ptr;
        delete temp;
    }

    string peek() const
    {
        if (!top)
        {
            cout << "Stack is empty" << endl;
            return "";
        }
        return top->name;
    }

    void display_stack()
    {
        Node *current = top;
        if (!current)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        while (current != nullptr)
        {
            cout << current->name;
            current = current->next_ptr;
            if (current != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }

    Node *get_top() const
    {
        return top;
    }

    bool is_empty() const
    {
        return top == nullptr;
    }
};

int main()
{
    Node *node1 = new Node("Zaza");
    Node *node2 = new Node("Zizi");
    Node *node3 = new Node("Zuzu");

    Stack stack;
    stack.push(node1);
    stack.push(node2);
    stack.push(node3);

    cout << "Stack : ";
    stack.display_stack();

    cout << "Top element : " << stack.peek() << endl;
    cout << "Stack after peek : " << endl;
    stack.display_stack();

    cout << "After popping top element : " << endl;
    stack.pop();
    stack.display_stack();

    // Cleanup
    Node *current = stack.get_top();
    while (current)
    {
        Node *temp = current;
        current = current->next_ptr;
        delete temp;
    }

    return 0;
}
