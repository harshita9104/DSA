//You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.

//Optimal - in a single pass

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posindex=0, negindex = 1;
        for(int i = 0; i<n; i++){
            if(nums[i]> 0){
                ans[posindex]= nums[i];
                posindex += 2;

            }
            else{
                ans[negindex] = nums[i];
                negindex +=2;
            }
        }
        return ans;
        
    }
};



//variety 2 when the pos and neg elements are not eq in number if some elements are left then put them in the arr in same order.
//fall back to the brute force solution where we were storing pos and neg differently
//here we cant do it in a single pass as in that we inc the index by 2 and if the pos>neg and now only pos are left then the remaining positives will be getting filled in the ans arr leaving 1 index, so we use the brute force where we use pos and neg arr to store elements.