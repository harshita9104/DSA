class Solution {
public:
 int subsetsum(vector<int>& arr, int targetsum, int n) {
        // Create a DP table
        vector<vector<int>> dp(n + 1, vector<int>(targetsum + 1, 0));

        // Base case: There's always one way to achieve sum = 0 (by choosing an empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= targetsum; j++) {
                if (arr[i - 1] <= j) {
                    // Include or exclude the current element
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                } else {
                    // Exclude the current element
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Return the number of subsets that achieve the target sum
        return dp[n][targetsum];
    }
 //s1-s2 = d
        //s1+ s2 = total sum
        //so s1 = (total sum+d)/2
        // i just need to find whether a subset of sum s1 exist in the arr or not 
        //so if s1 exists then the other one will be s2 only 
        //so this problem became subset sum problem
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum =0;
        for(int i = 0; i<n; i++){
           totalsum += nums[i];
        }
        
        int targetsum = (totalsum + target)/2;
       // Edge case: If (totalsum + target) is odd or target is out of bounds, return 0
        if ((totalsum + target) % 2 != 0 || target > totalsum || target < -totalsum) {
            return 0;
        }
        return subsetsum(nums, targetsum, n);

    }
};