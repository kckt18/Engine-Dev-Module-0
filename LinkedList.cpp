#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next; //declares a pointer named next that stores the address of a node
                // -> operator means that we want to access the data stored by the pointer
};

class LinkedList {
    private: 
        Node* head;

    public: 
        
        LinkedList () {
            head = nullptr;
        }

        void pushFront(int value) {
            Node* n = new Node;
            n->data = value;
            n->next = head;
            head = n;
        }        
        
        void print() {
            Node* curr = head;

            while (curr != nullptr) {
                cout << curr->data << ' ';
                curr = curr->next;
            }
            cout << endl;
        }
        
        void printSpecific(int value) {
            Node* curr = head;

            while(curr != nullptr) {
                if(curr->data == value) {
                    cout << curr->data << endl;
                    break;
                }
                curr = curr->next;
            }
        }

        void remove(int value) {
            Node* curr = head;
            Node* prev = head;
            bool checker = false;

            if (head == nullptr) {
                cout << "Empty list!" << endl;
                return;
            }

            while(curr != nullptr) {
                if(curr->data == value) {
                    checker = true;
                    if(value == head->data) {
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
            } 
            else {
                cout << "That number isn't even in the list!" << endl;
                return;
            }
        }

        void reverse() {
            Node* curr = head;
            Node* prev = nullptr;
            Node* nextnode = nullptr;

            if (head == nullptr) {
                cout << "You tried reversing an empty list!" << endl;
                return;
            } 
            else if (head->next == nullptr) {
                cout << "Your list has just one node!" << endl;
                return;
            }

            while (curr!= nullptr) {
                nextnode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextnode;
            }

            head = prev;
        }
};

int main() {

    LinkedList list;
    int n;

    cout << "Enter the total numbers you want in the list initially:" << endl;
    cin >> n;
    if (n != 0) cout << "Enter the numbers: " << endl;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.pushFront(x);
    }

    cout << "Enter the number you want to remove: ";
    int y;
    cin >> y;
    list.remove(y);

    if (n!=0) cout << "Final list is: " << endl;
    list.print();

    list.reverse();
    list.print();

    return 0;
}