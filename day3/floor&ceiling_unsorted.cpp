//Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].

// Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than smallest element of Arr[].

// Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than greatest element of Arr[].

//linear search

    // Time complexity: O(N)
    // Space complexity: O(1)

    // Where 'N' is the size of array.

//while iterating thr arr we have to find the largest and smallest elem comp to x , so 1 cond will be comparison with x , a[i]<=x

//there will many elem smaller than x , but to find the largest among them put the condition a[i]> ans.first (which stores prev largest) 

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    //first elem of pair- floor since we have to look for the largest elem <= x, init value of floor shd be small , since while finding the largest elem we will compare a[i]> ans.first (which stores prev largest) 
    
    pair<int, int> ans = { -1, INT_MAX};

//second elem of pair - ceil, since we have to look for smallest elem >=x, init value of ceil shd be large, since while finding the smallest elem we will compare a[i]< ans.second(which store prev smallest)if elem smaller than this found in arr which is also >=x it will replace ceil.

    for (int i = 0; i < n; i++) {
      //ceil- to find the smallest elem which is >=x
        if (a[i] >= x && a[i] < ans.second)
            ans.second = a[i];
            //floor - to find the largest elem which is <=x
        if (a[i] <= x && a[i] > ans.first)
            ans.first = a[i];
    }
//if no ceil exists x is largest itself
    if (ans.second == INT_MAX)
        ans.second = -1;

    return ans;
}
