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

void insertBeginning(int val) {
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
    head = newNode;
}

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

void insertAfter(int val, int key) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node not found\n";
}

void insertBefore(int val, int key) {
    if (head == NULL) return;
    if (head->data == key) {
        insertBeginning(val);
        return;
    }
    Node* temp = head;
    while (temp->next != head && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next->data == key) {
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Node not found\n";
    }
}

void deleteSpecific(int key) {
    if (head == NULL) return;

    if (head->data == key && head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next != head && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next->data == key) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    } else {
        cout << "Node not found\n";
    }
}

void searchNode(int key) {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Not found\n";
}

void display() {
    if (head == NULL) {
        cout << "NULL\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(HEAD)\n";
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