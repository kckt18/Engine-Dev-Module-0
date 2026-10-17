
#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::pushFront(int value) {
    Node* n = new Node;
    n->data = value;
    n->next = head;
    head = n;
}

void LinkedList::print() {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

void LinkedList::printSpecific(int value) {
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == value) {
            cout << curr->data << endl;
            break;
        }
        curr = curr->next;
    }
}

void LinkedList::remove(int value) {
    Node* curr = head;
    Node* prev = head;
    bool checker = false;

    if (head == nullptr) {
        cout << "Empty list!" << endl;
        return;
    }

    while (curr != nullptr) {
        if (curr->data == value) {
            checker = true;
            if (value == head->data) {
                head = head->next;
                return;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (checker) {
        prev->next = curr->next;
    } else {
        cout << "That number isn't even in the list!" << endl;
        return;
    }
}

void LinkedList::reverse() {
    Node* curr = head;
    Node* prev = nullptr;
    Node* nextnode = nullptr;

    if (head == nullptr) {
        cout << "You tried reversing an empty list!" << endl;
        return;
    } else if (head->next == nullptr) {
        cout << "Your list has just one node!" << endl;
        return;
    }

    while (curr != nullptr) {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }

    head = prev;
}
