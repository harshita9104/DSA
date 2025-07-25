class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/2){
              ans = nums[i];
              break;
            }
        }
        return ans;
    }
};