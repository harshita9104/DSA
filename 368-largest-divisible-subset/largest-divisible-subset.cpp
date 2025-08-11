class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //We use dynamic programming to find the length of the largest divisible subset ending at each index. We maintain a dp array where dp[i] represents the length of the largest divisible subset ending at index i.
        int n=nums.size(), maxi=1, num=-1;
        vector<int>v;
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(!(nums[i]%nums[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    if(maxi<dp[i]){
                        maxi=dp[i];
                    }
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(maxi==dp[i] && (num==-1 || !(num%nums[i]))){
                v.push_back(nums[i]);
                maxi--;
                num=nums[i];
            }
        }
        return v;
    }
};