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

void createCircularList(int val) {
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

void displayRepeatedHead() {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main() {
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        cout << "Enter val: ";
        cin >> val;
        createCircularList(val);
    }

    cout << "Output: ";
    displayRepeatedHead();

    return 0;
}