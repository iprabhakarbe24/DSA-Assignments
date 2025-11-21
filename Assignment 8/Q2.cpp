#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) { data = v; left = right = nullptr; }
};

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else if (val > root->data) root->right = insertBST(root->right, val);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchItr(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

int findMin(Node* root) {
    while (root->left) root = root->left;
    return root->data;
}

int findMax(Node* root) {
    while (root->right) root = root->right;
    return root->data;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* curr = searchItr(root, key);
    if (!curr) return nullptr;

    if (curr->right) {
        curr = curr->right;
        while (curr->left) curr = curr->left;
        return curr;
    }

    Node* succ = nullptr;
    Node* ancestor = root;

    while (ancestor != curr) {
        if (curr->data < ancestor->data) {
            succ = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* curr = searchItr(root, key);
    if (!curr) return nullptr;

    if (curr->left) {
        curr = curr->left;
        while (curr->right) curr = curr->right;
        return curr;
    }

    Node* pred = nullptr;
    Node* ancestor = root;

    while (ancestor != curr) {
        if (curr->data > ancestor->data) {
            pred = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return pred;
}

int main() {
    cout << "\n Q2: BST Operations \n";

    int n;
    cout<<"enter no of nodes";
    cin >> n;

    Node* root = nullptr;
    vector<int> arr(n);
    cout<<"enter values in order";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        root = insertBST(root, arr[i]);
    }

    cout << "Min = " << findMin(root) << "\n";
    cout << "Max = " << findMax(root) << "\n";

    int key;
    cout<<"enter key to search for";
    cin >> key;
    cout << (searchRec(root, key) ? "Found Rec\n" : "Not Found Rec\n");
    cout << (searchItr(root, key) ? "Found Itr\n" : "Not Found Itr\n");

    Node* s = inorderSuccessor(root, key);
    if (s) cout << "Successor = " << s->data << "\n";
    else cout << "No Successor\n";

    Node* p = inorderPredecessor(root, key);
    if (p) cout << "Predecessor = " << p->data << "\n";
    else cout << "No Predecessor\n";

    return 0;
}
