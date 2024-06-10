//There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //the only condition where u wont be able to check that which part of arr is sorted is when (arr[low] == arr[mid] == arr[high]) so to remove this we shrink our arr untill the condn become false 
        //and we reach a state where we can compare arr[low] and arr[mid] and find out which part of the arr is sorted
        int n = nums.size();
        int low = 0; int high = n-1; int mid = low +(high - low)/2;
        while(low <= high){
            mid = low +(high - low)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low+1;
                high = high-1;
                continue;//to keep repeating this untill the cond become fals
            }
            
            //left sorted
            if(nums[low] <= nums[mid] ){
                if(target >= nums[low] && target<= nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                //right sorted 
                 if(target >= nums[mid] && target<= nums[high]){
                    low = mid +1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;

    }
};