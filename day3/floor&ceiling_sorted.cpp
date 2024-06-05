/*You're given a sorted array 'a' of 'n' integers and an integer 'x'.



Find the floor and ceiling of 'x' in 'a[0..n-1]'.


    Time Complexity : O(log(N))
    Space Complexoty: O(1)

    Where N is the size of the array.
*/

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
            ans = arr[mid];

            // We reduce search space to left half.
            h = mid - 1;
        }
        else
        {

            // We reduce search space to right half.
            l = mid + 1;
        }
    }
    return ans;
}
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
            ans = arr[mid];
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
