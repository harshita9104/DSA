Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.

Example:

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.
Input: price[] = [3]
Output: 3
Explanation: There is only 1 way to pick a piece of length 1.
Constraints:
1 ≤ price.size() ≤ 103
1 ≤ price[i] ≤ 106


class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();

        // Create the DP table
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//i represents the length of the rod piece you are currently considering.
// For example:
// When i = 1, you're considering pieces of length 1.
// When i = 2, you're considering pieces of length 2, and so on.
// What j Represents:

// j represents the remaining length of the rod that you are trying to maximize the profit for.

//Outer Loop (i):

// Iterates through all possible lengths of pieces (1 to n).
// i directly represents the length of the piece.
// Inner Loop (j):

// Iterates through all possible remaining lengths of the rod (1 to n).
// Condition if (i <= j) Explained:

// If the current piece of length i can fit into the remaining rod length j, you decide:
// Include the piece (price[i - 1] + dp[i][j - i]).
// Exclude the piece (dp[i - 1][j]).
// If i > j, you cannot include the piece, so you simply exclude it.
// Why i - 1 in price[i - 1]:

// The price array is 0-indexed, so the price of a piece of length i is stored at price[i - 1].
// Condition if (i <= j):
// This checks if the piece of length i can fit into the remaining rod length j.
// If i > j, you cannot use the piece of length i because it exceeds the remaining rod length.
// If i <= j, you have two choices:
// Include the piece of length i (and add its price to the solution for the remaining rod length j - i).
// Exclude the piece of length i and move to the next piece.
// Why This Eliminates the Need for a length Array:

// Since i directly represents the piece length, there's no need to create an explicit length array like [1, 2, 3, ..., n].

        // Fill the DP table
        for (int i = 1; i <= n; i++) { // Length of the pieces
            for (int j = 1; j <= n; j++) { // Remaining length of the rod
                if (i <= j) {
                    // Maximize the value by including or excluding the current piece
                    dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
                } else {
                    // Exclude the current piece
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The result is stored in dp[n][n]
        return dp[n][n];
    }
};
