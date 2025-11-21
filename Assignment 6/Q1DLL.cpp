#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node* head = NULL;

void insertBeginning(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

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
    newNode->prev = temp;
}

void insertAfter(int val, int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void insertBefore(int val, int key) {
    if (head == NULL) return;
    if (head->data == key) {
        insertBeginning(val);
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }
    Node* newNode = new Node(val);
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteSpecific(int key) {
    if (head == NULL) return;
    Node* temp = head;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val, key;
    while (true) {
        cout << "\n1. Insert Begin\n2. Insert End\n3. Insert After\n4. Insert Before\n5. Delete Specific\n6. Search\n7. Display\n8. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Val: "; cin >> val; insertBeginning(val); break;
            case 2: cout << "Val: "; cin >> val; insertEnd(val); break;
            case 3: cout << "Val: "; cin >> val; cout << "After key: "; cin >> key; insertAfter(val, key); break;
            case 4: cout << "Val: "; cin >> val; cout << "Before key: "; cin >> key; insertBefore(val, key); break;
            case 5: cout << "Delete key: "; cin >> key; deleteSpecific(key); break;
            case 6: cout << "Search key: "; cin >> key; searchNode(key); break;
            case 7: display(); break;
            case 8: return 0;
        }
    }
}