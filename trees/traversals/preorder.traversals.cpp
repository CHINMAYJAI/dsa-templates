#include<bits/stdc++.h>
using namespace std;

// recursive traversal
void preorderTraversal(Node* node) {
    if (node==NULL) return;
    cout<<node->right;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// iterative traversal
vector<int> iterativePreorderTraversal(Node* node) {
    vector<int>preorder;
    if (root==NULL) return preorder;
    stack<Node*> st;
    st.push(node);
    while(!st.empty()) {
        node=st.top();
        st.pop();
        preorder.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return preorder;
}