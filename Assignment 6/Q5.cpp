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
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void makeCircular() {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
}

bool isCircular() {
    if (head == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, val, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(val);
    }

    cout << "Do you want to connect the last node to the head (Make it Circular)?\n";
    cout << "1. Yes\n2. No\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        makeCircular();
    }

    if (isCircular()) {
        cout << "Output: The Linked List is Circular\n";
    } else {
        cout << "Output: The Linked List is NOT Circular\n";
    }

    return 0;
}