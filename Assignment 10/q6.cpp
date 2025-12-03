#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){ data = x; left = right = NULL; }
};

bool check(Node* root, unordered_set<int>& s){
    if(!root) return false;

    if(s.count(root->data)) return true;
    s.insert(root->data);

    return check(root->left, s) || check(root->right, s);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(2); // duplicate

    unordered_set<int> s;
    if(check(root, s)) cout << "Duplicates Found";
    else cout << "No Duplicates";
}
