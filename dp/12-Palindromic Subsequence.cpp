Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s; // t will store the reversed string of s
        reverse(t.begin(), t.end()); // reverse s to get t
        
        // ab hmare pass 2 string hai 
        // t string s ki reversed hai 
        // ab in dono m jo lcs aayegi vahi palindrome hogi 
        // lcs palindrome hai tabhi to s or uski reversed string m bhi present hai vo bhi same order m
        
        int n = s.size(); // length of the string
        // dp[i][j] will store LCS length for s[0..i-1] and t[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // fill dp table using classic LCS logic
        for(int i =1; i<= n; i++){
            for(int j =1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    // agar dono char equal hai to 1 add karenge diagonal se
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    // agar char equal nahi hai to max le lo left ya up cell se
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // dp[n][n] will give the length of longest palindromic subsequence
        return dp[n][n];
    }
};
