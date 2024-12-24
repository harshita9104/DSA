//Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Example 1:

// Input: nums = [3,2,3]
// Output: 3

//brute force - TLE error
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++ ){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(nums[j] == nums[i]){
                    count++;
                    if(count > (n/2)){
                        ans = nums[i];
                    }
                }
            }
        }
        return ans;
    }
//better - use hashing
int majorityElement(vector<int>& nums) {
        map<int, int>mpp;
        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            if(it.second > (nums.size())/2){
                return it.first;
            }
        }
        return -1;
    }