#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        this->val = data;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Method to get the value at a specific index
    int get(int index) {
        Node* temp = head;
        // Traverse the list up to the specified index
        for (int i = 0; temp != NULL && i < index; i++) {
            temp = temp->next;
        }
        // If the index is out of bounds, return -1
        if (temp == NULL) {
            return -1;
        }
        return temp->val;
    }

    // Method to add a node at the head
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        // If the list is empty, initialize head and tail to the new node
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    // Method to add a node at the tail
    void addAtTail(int val) {
        Node* newnode = new Node(val);
        // If the list is empty, initialize head and tail to the new node
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    // Method to add a node at a specific index
    void addAtIndex(int index, int val) {
        // If index is negative, do nothing
        if (index < 0) return;

        // Special case for adding at the head
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newnode = new Node(val);
        Node* temp = head;
        // Traverse to the node just before the specified index
        for (int i = 0; temp != NULL && i < index - 1; i++) {
            temp = temp->next;
        }
        // If the index is out of bounds, do nothing
        if (temp == NULL) return;

        // Insert the new node
        newnode->next = temp->next;
        temp->next = newnode;

        // If the new node is added at the end, update the tail
        if (newnode->next == NULL) {
            tail = newnode;
        }
    }

    // Method to delete a node at a specific index
    void deleteAtIndex(int index) {
        // If the list is empty or index is negative, do nothing
        if (index < 0 || head == NULL) return;

        // Special case for deleting the head
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;

            // If the list becomes empty, update the tail to NULL
            if (head == NULL) {
                tail = NULL;
            }
            return;
        }

        Node* temp = head;
        // Traverse to the node just before the specified index
        for (int i = 0; temp != NULL && i < index - 1; i++) {
            temp = temp->next;
        }
        // If the index is out of bounds or the next node is NULL, do nothing
        if (temp == NULL || temp->next == NULL) return;

        // Delete the node
        Node* indexnode = temp->next;
        temp->next = temp->next->next;
        delete indexnode;

        // If the deleted node was the last node, update the tail
        if (temp->next == NULL) {
            tail = temp;
        }
    }
};

int main() {
    MyLinkedList* list = new MyLinkedList();

    list->addAtHead(1);
    list->addAtTail(3);
    list->addAtIndex(1, 2);
    cout << list->get(1) << endl; // Output: 2

    list->deleteAtIndex(1);
    cout << list->get(1) << endl; // Output: 3

    delete list; // Free the allocated memory
    return 0;
}
