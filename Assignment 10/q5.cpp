#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data = x; next = NULL; }
};

bool hasCycle(Node* head){
    unordered_set<Node*> s;

    Node* curr = head;
    while(curr){
        if(s.count(curr)) return true;
        s.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;  // loop here

    cout << (hasCycle(a) ? "true" : "false");
}
