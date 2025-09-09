class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        string ans = "";
        //fill lcs table first
        for(int i =1; i<=n ; i++){
            for(int j =1; j<= m; j++){
                if(str1[i-1] == str2[j-1]){
                  dp[i][j] = 1+ dp[i-1][j-1];
                }else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
        }
        //now start travelling this filled  dp matrix  from last cell
        //is the corresponding char are eq then include it in ans only once
        //if not eq then before moving to that max precedent include that char in ans string
        int x = n;
        int y = m;
        while(x>0 && y>0){
            if(str1[x-1] == str2[y-1]){
                ans.push_back(str1[x-1]);
                x--;
                y--;
            }else if(dp[x-1][y] > dp[x][y-1]){
                ans.push_back(str1[x-1]);
                x--;//jo max h uski taraf move kr jaao
            }else {
                ans.push_back(str2[y-1]);
                y--;
            }
        }
        while(x>0){
             ans.push_back(str1[x-1]);
                x--;
        }
        while(y>0){
             ans.push_back(str2[y-1]);
                y--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};