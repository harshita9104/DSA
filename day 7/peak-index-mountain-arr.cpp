//You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() -1;
        while(low<= high){
            int mid = low+(high - low)/2;
            if(arr[mid]> arr[mid+1] && arr[mid]> arr[mid-1]){
                return mid;
            } else if(arr[mid]< arr[mid+1]){
                low = mid +1;
            }else if(arr[mid]< arr[mid-1]){
                high = mid - 1;
            }
        }
        return -1;
    }
};
