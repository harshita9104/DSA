class Solution {
public:

//The problem is best solved using dynamic programming with a dp[left][right] table.

// Steps to Solve the Problem
// Sort the Cuts Array

// Add 0 (start of the stick) and n (end of the stick) to the cuts array to simplify the calculation of stick lengths.
// Define the DP State

// Let dp[left][right] represent the minimum cost of cutting the stick between cuts[left] and cuts[right].
// Base Case

// If there are no cuts between cuts[left] and cuts[right] (i.e., right - left <= 1), the cost is 0.
// Recursive Transition

// For each interval [left, right], consider all possible cuts k between left and right. The cost of cutting at k is (cuts[right] - cuts[left]), plus the cost of cutting the left and right segments recursively:


// The result is stored in dp[0][cuts.size() - 1], which represents the minimum cost of cutting the entire stick.

// Sort the Cuts Array:

// Adding 0 and n ensures that all intervals are considered, and sorting ensures that the cuts are processed in order.
// Iterate Over Intervals:

// The outer loop processes intervals of increasing length (length), ensuring that smaller subproblems are solved before larger ones.
// Try All Possible Cuts:

// For each interval [left, right], try all cuts k within the interval and calculate the cost of cutting at k.
// Store the Minimum Cost:

// The minimum cost for each interval [left, right] is stored in dp[left][right].
// Return the Result:

// The result for the entire stick is stored in dp[0][m - 1].
// Complexity Analysis
// Time Complexity
// Sorting the cuts array: O(m log m), where m = cuts.size().
// Filling the DP table: O(m^3), as there are O(m^2) intervals and O(m) cuts to try for each interval.
// Overall Complexity: O(m^3).

// Space Complexity
// The dp table requires O(m^2) space.

    int minCost(int n, vector<int>& cuts) {
        // Add the start and end points of the stick to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        // DP table to store minimum cost for each interval
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Fill the DP table
        for (int length = 2; length < m; length++) { // Length of the interval
            for (int left = 0; left < m - length; left++) {
                int right = left + length;
                dp[left][right] = INT_MAX;

                // Try all possible cuts between left and right
                for (int k = left + 1; k < right; k++) {
                    int cost = cuts[right] - cuts[left]; // Cost of current cut
                    dp[left][right] = min(dp[left][right], dp[left][k] + dp[k][right] + cost);
                }
            }
        }

        // The result is the minimum cost to cut the entire stick
        return dp[0][m - 1];
    }
};