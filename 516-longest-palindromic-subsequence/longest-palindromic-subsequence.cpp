class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        //ab hmare pass 2 string hai 
        //t string s ki reversed hai 
        //ab in dono m jo lcs aayegi vahi palindrome hogi , lcs palindrome hai tabhi to s or uski reversed string m bhi present hai vo bhi same order m

        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i =1; i<= n; i++){
            for(int j =1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];

        
    }
};