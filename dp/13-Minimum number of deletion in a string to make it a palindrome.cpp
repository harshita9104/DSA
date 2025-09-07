Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

Examples:

Input: s = "aebcbda"
Output: 2
Explanation: Remove characters 'e' and 'd'.
Input: s = "geeksforgeeks"
Output: 8
Explanation: To make "geeksforgeeks" a palindrome, the longest palindromic subsequence is "eefee" (length 5). The minimum deletions are:
13 (length of s) - 5 = 8.
Constraints:
1 ≤ s.size() ≤ 103


  class Solution {
  public:
    int minDeletions(string s) {
        // Logic: Minimum deletions to make s a palindrome = total length - length of longest palindromic subsequence.

        string t = s; // t will be reversed string of s
        reverse(t.begin(), t.end()); // reverse s to get t

        // ab hmare pass 2 string hai 
        // t string s ki reversed hai 
        // ab in dono m jo lcs aayegi vahi palindrome hogi
        // lcs palindrome hai tabhi to s or uski reversed string m bhi present hai vo bhi same order m

        int n = s.size(); // length of original string

        // dp[i][j] stores length of LCS between s[0..i-1] and t[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == t[j-1]) {
                    // agar current char same hai to diagonal se +1 add karo
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    // agar current char alag hai to max lo left or up se
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // s.size() - dp[n][n] = minimum deletions to make palindrome
        // longest palindromic subsequence ke alawa baaki sabko delete karna padega
        return s.size() - dp[n][n];
    }
};
