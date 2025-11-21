#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

void insertEnd(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; 
}

int getSize() {
    if (head == NULL) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    int n, val;
    cout << "Enter number of elements for Circular Linked List: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(val);
    }

    cout << "Size of the Circular Linked List is: " << getSize() << endl;

    return 0;
}