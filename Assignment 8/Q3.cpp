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

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        }
        if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* succ = root->right;
        while (succ->left) succ = succ->left;
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "\n=== Q3: BST Insert/Delete/Depth ===\n";

    int n;
    cout<<"enter no of nodes";
    cin >> n;

    vector<int> arr(n);
    Node* root = nullptr;
    cout<<"enter elements";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        root = insertBST(root, arr[i]);
    }

    cout << "Inorder before delete: ";
    inorder(root);
    cout << "\n";

    int key;
    cout<<"enter element to delete";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Inorder after delete: ";
    inorder(root);
    cout << "\n";

    cout << "Max Depth = " << maxDepth(root) << "\n";
    cout << "Min Depth = " << minDepth(root) << "\n";

    return 0;
}
