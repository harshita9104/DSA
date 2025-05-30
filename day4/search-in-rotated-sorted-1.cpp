// variety -1
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        //mistake high will point to n-1  
        int high = nums.size()-1;
        int mid = low+(high-low)/2;
        while(low<= high){
            mid = low+(high-low)/2;
            if(nums[mid] == target){
                return mid;
            }
            //left sorted 
            //mistake (eq to sign) condition for sorted (a<=b) 
            if(nums[low]<= nums[mid]){
                //check if target lie in left side or not
                if(target >= nums[low] && target <= nums[mid]){
                    // if target is in left side eliminate right
                    high = mid-1;
                }else{
                    //if target is not present in left side eliminte left 
                    low= mid+1;
                }

            }else{
                //right sorted 
                //check if target lie in right or not
                if(target >= nums[mid] && target <= nums[high]){
                    //eliminate left part
                    low = mid+1;
                }else {
                    high = mid -1;
                }
            }
        }
        return -1;
    }
};