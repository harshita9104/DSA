class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = 0;
        for(auto i : nums){
            mp[i]++;
            if(mp[i] > n/2)ans = i;
        
        }
        return ans;
    }
};