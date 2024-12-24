//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.
//since in xor operation(a^a = 0, a^0 = a) so the numbers which appears twice will xor and equates to 0 and the number which appears once upon being xored with 0 gives the number itself.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};