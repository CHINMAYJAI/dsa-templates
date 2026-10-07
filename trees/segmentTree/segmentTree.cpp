#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // building segment tree
        void buildTree(vector<int>array, int i, int l, int r) {
            if (l==r) {
                array[i]=array[l];
                return;
            }
            int mid=(l+r)>>1;
            buildTree(array,2*i+1,l,mid);
            buildTree(array,2*i+2,mid+1,r);
            array[i]=array[2*i+1]+array[2*i+2];
            return;
        }
        // query update in a range
        void queryUpdate(vector<int>array, int ind, int val, int i, int l, int r) {
            if (l==r) {
                array[ind]=val;
                return;
            }
            int mid=(l+r)>>1;
            if (ind<=mid) queryUpdate(array,ind,val,2*i+1,l,mid); // left child
            else queryUpdate(array,ind,val,2*i+2,mid+1,r); // right child
            array[i]=array[2*i+1]+array[2*i+2];
            return;
        }
        // how to perform calculations on given range
        /*
        there will be three cases
        case 1. out of bound ==> return 0;
        case 2. partially contribute to range ==> return func(left)+func(right);
        case 3. completely contribute to range ==> return array[i]; (return entire node value)
        */
        int rangeQuery(vector<int>array, int start, int end, int ind, int l, int r) {
            if (l>=start && r<=end) return array[ind]; // completely contribute to range
            if (l>end || r<start) return 0; // out of bound
            int mid=(l+r)>>1;
            // partially contribute to range
            return rangeQuery(array,start,end,2*ind+1,l,mid)+rangeQuery(array,start,end,2*ind+2,mid+1,r);
        }
};

int main() {
    return 0;
}