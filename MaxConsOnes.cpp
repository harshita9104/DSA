//leetcode 268
//Given a binary array nums, return the maximum number of consecutive 1's in the array.
// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcount =0;//mistake- initialise maxcount otherwise it will assume any random variable initially.
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] ==1){
                count++;
                 maxcount = max(count, maxcount);
                
            }else(nums[i] == 0){
               
                count = 0;

            }


        }
        return maxcount;
    }
};