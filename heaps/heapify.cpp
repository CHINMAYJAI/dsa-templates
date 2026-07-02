#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void heapifyUp(vector<int>&nums, int ind) {
        int parent=(ind-1)/2;
        if (ind>0 && nums[parent]>nums[ind]) {
            swap(nums[parent],nums[ind]);
            heapifyUp(nums,parent);
        }
    }
    void heapifyDown(vector<int>&nums, int ind) {
        int n=nums.size();
        int leftChild=(ind*2)+1, rightChild=(ind*2)+2;
        int smallestInd=ind;
        if (leftChild<n && nums[leftChild]<nums[smallestInd]) smallestInd=leftChild;
        if (rightChild<n && nums[rightChild]<nums[smallestInd]) smallestInd=rightChild;
        if (smallestInd!=ind) {
            swap(nums[smallestInd],nums[ind]);
            heapifyDown(nums,smallestInd);
        }
    }
    public:
    void heapify(vector<int>&nums, int ind, int val) {
        if (nums[ind]<val) {
            nums[ind]=val;
            heapifyDown(nums,ind);
        }
        else {
            nums[ind]=val;
            heapifyUp(nums,ind);
        }
    }
};
