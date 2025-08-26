class Solution {
public:
    int dp[20]{};
    int numTrees(int n) {

        //Basic Intuition for this solution is using Dynamic Programming with memorization. For all possible values of i, consider i as root, then [1 . . . i-1] numbers will fall in the left subtree and [i+1 . . . N] numbers will fall in the right subtree.

// Then all possible BST’s will be
// numTrees(N) = summation of (numTrees(i-1)*numTrees(N-i)) where i lies in the range [1, N].

// Approach
// Follow the below steps to Implement the idea:

// Create an array dp of size 20 (max 20 nodes as given)
// dp[0] = 1 and dp[1] = 1. (Base condition)
// Run for loop from i = 1 to i <= n and call recursion for each i.
// dp[n] += numTrees(i-1) * numTrees(n-i); , this line fills the complete dp array.
// if(dp[n]) return dp[n]; , here we simply return the dp[n] if it's already filled so that we can avoid unneccesary recursion and calculations.

        if(n <= 1) return 1;
        if(dp[n]) return dp[n];
        for(int i = 1; i <= n; i++) 
            dp[n] += numTrees(i-1) * numTrees(n-i);
        return dp[n];
    }
};