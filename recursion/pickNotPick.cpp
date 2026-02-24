#include <bits/stdc++.h>
using namespace std;

// contains duplicates
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

// does not contains duplicates
void fn(int ind, vector<vector<int>>& ds, vector<int>arr, vector<int>nums) {
    if (ind>=nums.size()) {
        // condition
        ds.push_back(arr);
        return;
    }
    // condition (if any)
    for (int i=ind;i<nums.size();i++) {
        if (i>ind && nums[i]==nums[i-1]) continue;
        // operations (if any)
        arr.push_back(nums[i]);
        fn(i+1,ds,arr,nums);
        // operations (if any)
        arr.pop_back();
    }
}