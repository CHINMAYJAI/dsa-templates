#include<bits/stdc++.h>
using namespace std;

vector<int>pseFn(vector<int>list) {
    int n=list.size();
    vector<int>pse(n,-1);
    stack<int>st;
    for (int i=0;i<n;i++) {
        while(!st.empty() && st.top()>=list[i]) st.pop();
        if (!st.empty()) pse[i]=st.top();
        st.push(list[i]);
    }
    return pse;
}

vector<int>ngeFn(vector<int>list) {
    int n=list.size();
    vector<int>nge(n,-1);
    stack<int>st;
    for (int i=n-1;i>=0;i--) {
        while(!st.empty() && st.top()<=list[i]) st.pop();
        if (!st.empty()) nge[i]=st.top();
        st.push(list[i]);
    }
    return nge;
}