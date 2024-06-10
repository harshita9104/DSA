/*You're given a sorted array 'a' of 'n' integers and an integer 'x'.
Find the floor and ceiling of 'x' in 'a[0..n-1]'.
  Time Complexity : O(log(N))
    Space Complexoty: O(1)

    Where N is the size of the array.
*/
//ceil is the smallest elem >=x
int getCeil(int n, int x, vector<int> &arr)
{
    int ans = -1;

    // Initial range of search
    int l = 0, h = n - 1;
    while (l <= h)
    {

        int mid = (l + h) / 2;

        // Array element at Mid is greater than x.
        if (arr[mid] >= x)
        {
            //since this can be a possible ans we stored it in ans 
            ans = arr[mid];

//since we need smallest elem and arr[mid] can be a possible ans we will look for an elem which is smallest and also >=x so we can reduce our search space to left side as arr is sorted so left  will have elem less than mid elem 
            // We reduce search space to left half.

            h = mid - 1;
        }
        else
        {// We reduce search space to right half.
            l = mid + 1;
        }
    }
    return ans;
}
//floor- largest elem <=x 
int getFloor(int n, int x, vector<int> &arr)
{
    int ans = -1;

    // Initial range of search
    int l = 0, h = n - 1;
    while (l <= h)
    {

        int mid = (l + h) / 2;

        // Array element at Mid is less than x.
        if (arr[mid] <= x)
        {
        // this can be a possible answer so store it
            ans = arr[mid];
            //since we have to find largest elem <=x so we can reduce the search space to right side as right will have elem greater than mid so if any elem in right is  <= x , it will replace ans.
            // We reduce search space to right half.
            l = mid + 1;
        }
        else
        {
            // We reduce search space to left half.
            h = mid - 1;
        }
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    return make_pair(getFloor(n, x, a), getCeil(n, x, a));
}
