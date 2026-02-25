#include <bits/stdc++.h>
using namespace std;

// Backtracking (Using visited[])
void permute1(vector<vector<int>>ds, vector<int>& nums, vector<int>& curr, vector<bool>& used) { // vector<bool> used(nums.size(), false);
    if (curr.size() == nums.size()) {
        ds.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        curr.push_back(nums[i]);
        permute1(ds, nums, curr, used);
        curr.pop_back();
        used[i] = false;
    }
}

// Backtracking (Swap Method – More Optimized)
void permute2(vector<vector<int>>&ds, vector<int>& nums, int index) {
    if (index == nums.size()) {
        ds.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        permute2(ds, nums, index + 1);
        swap(nums[index], nums[i]); // backtrack
    }
}

// Using STL next_permutation()
void permute3() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>>ds;
    sort(nums.begin(), nums.end());
    bool flag=false;
    while (!flag) {
        next_permutation(nums.begin(),nums.end());
        for (int i=0;i<ds.size();i++) {
            if (nums==ds[i]) {
                flag = true;
                break;
            }
        }
        if (!flag) ds.push_back(nums);
    }
}