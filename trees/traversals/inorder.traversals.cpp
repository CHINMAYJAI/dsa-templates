#include<bits/stdc++.h>
using namespace std;

// recursive traversal
void inorderTraversal(Node* node) {
    if (node==NULL) return;
    inorderTraversal(node->left);
    cout<<node->data;
    inorderTraversal(node->right);
}

// iterative traversal
vector<int> iterativeInorderTraversal(Node* root) {
    vector<int>inorder;
    if (root==NULL) return inorder;
    Node* node=root;
    stack<Node*>st;
    while(!st.empty()) {
        if (node) {
            st.push(node);
            node=node->left;
        }
        else {
            node=st.top();
            st.pop();
            inorder.push_back(node->val);
            node=node->right;
        }
    }
    return inorder;
}