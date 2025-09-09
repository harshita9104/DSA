Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.


cant use map approach in this becoz the order of char  also need to be checked
//two pointer 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // pointer for string s
        int j = 0; // pointer for string t
        
        // Use two pointers to check if s is subsequence of t
        while (i < s.size() && j < t.size()) {
            // If characters match, move both pointers
            if (s[i] == t[j]) {
                i++;
            }
            // Always move pointer for t
            j++;
        }
        
        // If we've matched all characters of s, return true
        return i == s.size();
    }
};

//DP - LCS

 //using lcs
        // if  length of lcs- longest common subseq is eq to s.size() then true
        //fill lcs table
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i =1; i<= n; i++){
            for(int j =1; j<= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m] == s.size();
