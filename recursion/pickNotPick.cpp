#include <bits/stdc++.h>
using namespace std;
void fn(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int i)
{
    if (i == arr.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    fn(arr, ans, temp, i + 1);
    temp.pop_back();
    fn(arr, ans, temp, i + 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> ans;
    vector<int> temp;
    fn(v, ans, temp, 0);
    for (int i = 0; i < (1 << n); i++)
    {
        int sz = ans[i].size();
        for (int j = 0; j < sz; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}