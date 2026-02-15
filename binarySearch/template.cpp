int binary_search(vector<int>& arr, int x) {
    int left = 0, right = a.size() - 1;
    int mid;
    while (left <= right) {
        // another ways to calc mid -> `(left+right)/2` or `(left+right)>>1`
        mid = left + (right - left) / 2;
        if (arr[mid] == x) break;
        else if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return mid;
}
