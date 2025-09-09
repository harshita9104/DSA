Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.


class Solution {
public:
    int minInsertions(string s) {
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
        //jitne char ko delete krke lps milega = s.size() - lps length (dp[n][m])
        //agar m vahi char add krdu jaise e ka occ ek baar h mai ek specific jagah par e ko add krdu to ho skta h palindrome ban jae string
        //this is valid for all char which shd be removed to make this s string a palindrome
        //agar ye sare char ko unke opp side par ek specific jagah insert kre to palindrome ban skta
        return s.size()- dp[n][n];
    }
};

