/*
id: 22011059
name: noor zaheera
group: g3
lab: L6
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Add new node at the end
    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (front == nullptr) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
        }
    }

    // Remove node from the front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next_ptr;
        cout << "Dequeued : " << temp->name << endl;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Display the queue
    void display_queue() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Zaza");
    q.enqueue("Zizi");
    q.enqueue("Zuzu");

    cout << "Queue : ";
    q.display_queue();

    q.dequeue();

    cout << "After dequeueing : ";
    q.display_queue();

    return 0;
}
