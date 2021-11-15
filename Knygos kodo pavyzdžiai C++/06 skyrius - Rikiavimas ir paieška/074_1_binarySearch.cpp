int binSearch(int x, vector<int> arr) {
    int lo = 0, hi = masyvas.size()-1;
    // ieskome intervale [0, n-1]
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (arr[mid] < x) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    return mid;
}