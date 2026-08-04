#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) {
        val=data;
        left = right = nullptr;
    }
};

class Solution {
private:
    // Parses "[1,2,3,null,4]"
    vector<string> parseInput(string s) {
        vector<string> nodes;
        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());
        stringstream ss(s);
        string token;
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }
        return nodes;
    }

    // Builds tree from vector<string>
    TreeNode* buildTree(vector<string> &nodes) {
        if (nodes.empty() || nodes[0] == "null")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();
            // Left child
            if (i < nodes.size() && nodes[i] != "null") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;
            // Right child
            if (i < nodes.size() && nodes[i] != "null") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }

    // Prints tree in LeetCode format
    void printTree(TreeNode* root) {
        if (!root) {
            cout << "[]\n";
            return;
        }
        vector<string> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                ans.push_back(to_string(curr->val));
                q.push(curr->left);
                q.push(curr->right);
            }
            else {
                ans.push_back("null");
            }
        }
        while (!ans.empty() && ans.back() == "null")
            ans.pop_back();
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i + 1 != ans.size())
                cout << ",";
        }
        cout << "]\n";
    }

public:
    // Example function returning root
    TreeNode* solve(TreeNode* root) {
        // Write your solution here
        return root;
    }

    void run() {
        string s;
        cin >> s;
        vector<string> nodes = parseInput(s);
        TreeNode* root = buildTree(nodes);
        root = solve(root);
        printTree(root);
    }
};

