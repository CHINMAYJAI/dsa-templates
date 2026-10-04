#include<bits/stdc++.h>
using namespace std;

// recursive traversal
void postorderTraversal(Node* node) {
    if (node==NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout<<node->data;
}

// iterative traversal (using 2 stacks)
vector<int> iterativePostorderTraversal(TreeNode* node) {
    vector<int>postorder;
    if (node==NULL) return postorder;
    stack<TreeNode*> st1, st2;
    st1.push(node);
    while (!st1.empty()) {
        node=st1.top();
        st1.pop();
        st2.push(node);
        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);
        while(!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
    }
    return postorder;
}


// iterative traversal (using 1 stacks)
vector<int> postorderTraversal(Node* root) {
    vector<int> result;
    stack<Node*> st;
    Node* curr = root;
    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        Node* temp = st.top()->right;
        if (temp == nullptr) {
            temp = st.top();
            st.pop();
            result.push_back(temp->data);
            while (!st.empty() && temp == st.top()->right) {
                temp = st.top();
                st.pop();
                result.push_back(temp->data);
            }
        }
        else curr = temp;
    }

    return result;
}
