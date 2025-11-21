#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) { data = v; left = right = nullptr; }
};

Node* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front(); q.pop();

        if (i < arr.size() && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}


bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;

    if (root->data <= minVal || root->data >= maxVal) return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    cout << "\n=== Q4: Check BST ===\n";

    int n;
    cout<<"enter no of nodes";
    cin >> n;

    vector<int> arr(n);
    cout<<"enter elements";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);

    if (isBST(root))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
