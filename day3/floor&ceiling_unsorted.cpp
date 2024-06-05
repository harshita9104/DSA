//Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].

// Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than smallest element of Arr[].

// Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than greatest element of Arr[].

//linear search

    // Time complexity: O(N)
    // Space complexity: O(1)

    // Where 'N' is the size of array.


pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    pair<int, int> ans = { -1, INT_MAX};

    for (int i = 0; i < n; i++) {
      //ceil- to find the smallest elem which is >=x
        if (a[i] >= x && a[i] < ans.second)
            ans.second = a[i];
            //floor - to find the largest elem which is <=x
        if (a[i] <= x && a[i] > ans.first)
            ans.first = a[i];
    }

    if (ans.second == INT_MAX)
        ans.second = -1;

    return ans;
}