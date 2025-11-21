#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = NULL;
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
    newNode->prev = temp;
}

bool isPalindrome() {
    if (head == NULL) return true;

    Node* left = head;
    Node* right = head;

    // Find tail
    while (right->next != NULL) {
        right = right->next;
    }

    while (left != right && right->next != left) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    int n;
    int val;
    cout << "Enter number of val ";
    cin >> n;
    cout << "Enter val: \n";
    for(int i=0; i<n; i++) {
        cin >> val;
        insertEnd(val);
    }

    if (isPalindrome()) {
        cout << "The list is a Palindrome\n";
    } else {
        cout << "The list is NOT a Palindrome\n";
    }
    return 0;
}