same as partition arr into 2 subset with given diff
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000


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
