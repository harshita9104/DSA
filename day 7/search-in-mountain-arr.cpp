/**
 * // This is the MountainArray's API interface.
 * You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.

 */

class Solution {
public:
// int ascendingBinarySearch( MountainArray &arr, int low,
// int high, int target){
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (arr.get(mid) == target)
//             return mid;
//         if (arr.get(mid) > target)
//             high = mid - 1;
//         else
//             low = mid + 1;
//     }
//     return -1;

//     }
//     int decendingBinarySearch(MountainArray &arr, int low,
//     int high, int target){
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (arr.get(mid) == target)
//             return mid;
//         if (arr.get(mid) > target)
//              low = mid + 1;
//         else
//             high = mid - 1;
//     }
//     return -1;

//     }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int low = 0; int high = n-1;
        int peak = 0;
        //this code to find peak elem shows TLE err
        // while(low<= high){
        //     int mid = low+(high - low)/2;
        //     int x = arr.get(mid);
        //     if(x > arr.get(mid+1) && x > arr.get(mid-1)){
        //          peak =  mid;
        //     } else if(x <  arr.get(mid+1)){
        //         low = mid +1;
        //     }else if(x < arr.get(mid-1)){
        //         high = mid - 1;
        //     }
        //     }
         low   = 0;
    high = n - 1;
        while (low < high) {
            int m = (low + high) / 2;
            if (arr.get(m) < arr.get(m + 1))
                low = peak = m + 1;
            else
                high = m;
        }
            // return min(ascendingBinarySearch(arr, 0, peak-1, target), decendingBinarySearch(arr, peak, n-1, target));
            //binary search in ascending 
            low = 0; 
            high = peak -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int y = arr.get(mid);
        if (y  == target){
            return mid;

        }else if(y  > target) {
            
            high = mid - 1;

        }
            
        else{
             low = mid + 1;

        }
           
    }
    //binary search in descending portion
    low = peak;
    high = n-1;
   while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int y = arr.get(mid);
        if (y  == target){
            return mid;

        }else if  (y  > target){
           
            low= mid + 1;

        }
            
        else{
             high = mid - 1;

        }
           
    }
    return -1;

    }
    
};