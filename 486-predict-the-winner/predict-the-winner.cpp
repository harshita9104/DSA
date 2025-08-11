class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {

        //1.Initialize dp[i] = nums[i] — this represents the base case when i == j.

// 2.For all subarrays from length 2 to n:

// Update dp[j] using:

// nums[i] - dp[j] → if taking the left element.

// nums[j] - dp[j - 1] → if taking the right element.

// Take the max of these two, as Player 1 wants to maximize the lead.

// 3.In the end, if the lead is >= 0, Player 1 can win or tie.
        int n = nums.size();
        vector<int> dp(nums);
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
        return dp[n - 1] >= 0;
    }
};

