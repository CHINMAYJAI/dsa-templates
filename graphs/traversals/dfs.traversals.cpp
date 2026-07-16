#include<bits/stdc++.h>
using namespace std;

vector<int>dfsTraversal(int V, vector<int>adj[], int visited[], vector<int>& dfs) {
    visited[V]=1;
    dfs.push_back(V);
    for (auto it:adj[V]) {
        if (!visited[it]) {
            dfsTraversal(it, adj, visited, dfs);
        }
    }
    return dfs;
}