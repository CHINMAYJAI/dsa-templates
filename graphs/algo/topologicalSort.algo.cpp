#include<bits/stdc++.h>
using namespace std;

// based on dfs topological sort

void dfsTraversal(int node, vector<int>adj[], int visited[],stack<int>st) {
    visited[node]=1;
    for (auto it:adj[node]) {
        if(!visited[it]) dfsTraversal(it,adj,visited,st);
    }
    st.push(node);
}

vector<int>topologicalSort(int V, vector<int> adj[]) {
    stack<int>st;
    int visited[V]={0};
    for (int i=0;i<V;i++) {
        if (!visited[i]) {
            dfsTraversal(i,adj[],visited,st);
        }
    }
    vector<int>ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}