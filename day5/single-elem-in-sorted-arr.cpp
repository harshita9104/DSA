//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space
//brute force solution
//considering the fact that in sorted arr for the elem to appear once
//the elem arr[i] != arr[i-1] && arr[i] != arr[i+1]
//also consider the case when i = 0 & i = n-1

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n ==1){
            return nums[0];
        }
        for(int i = 0; i<nums.size(); i++){
            if(i == 0){
                if(nums[i] != nums[i+1]){
                    return nums[i];
                }

                }else if(i == n-1){
                     
                if(nums[i] != nums[i-1]){
                    return nums[i];
            }

        }else if(nums[i] != nums[i+1] && nums[i] != nums[i-1]){
        
            return nums[i];
        }
    }
    return -1;

    }
};
//optimal
