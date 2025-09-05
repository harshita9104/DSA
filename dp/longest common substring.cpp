You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
Input: s1 = "YZ", s2 = "yz"
Output: 0
Constraints:
1 <= s1.size(), s2.size() <= 103
Both strings may contain upper and lower case alphabets.



class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m +1));
        int maxi =0;//this will keep track of max length of cont common elem wali substring
        //whole matrix is intialised with 0 and 0th row and 0th col says one of the string is empty 
        //that means there is nothing in common so len of common substring should be zero
        for(int  i =0; i<=n; i++){
            dp[i][0] =0;
        }
         for(int  j =0; j<=m; j++){
            dp[0][j] =0;
        }
        for(int  i =1; i<=n; i++){
            for(int j =1; j<= m; j++){
                if(s1[i-1] == s2[j-1]){//jab jab continuous common elem aayenge  +1 hota jaega prev count m or maxi , will store max length of such counts
                    //if both elem are eq we count this common char and call for smaller string size for both
                    dp[i][j] = 1+dp[i-1][j-1];
                    maxi = max(maxi, dp[i][j]);
                }else{
                    dp[i][j] = 0;//if we found a non eq elem then we make this 0, becoz substring with common elem wont be continued from here 
                }
            }
        }
        return maxi;
    }
};
