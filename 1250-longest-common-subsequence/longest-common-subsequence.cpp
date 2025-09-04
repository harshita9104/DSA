class Solution {
public:
//memoised - bottomup 
// int  t[1001][1001];
// int solve(string text1, string text2, int n , int m){
//    if(n == 0||m ==0)return 0;//jab string m kuch hai hi nhi to common kya hoga
//    if(t[n][m] != -1)return t[n][m];
//         if(text1[n-1] == text2[m-1]){
//             t[n][m] = 1 + solve(text1, text2, n-1, m-1);
//         }else{
//             //we have 2 choices ek baar text1 ki size kam kro ek baar text2 ki jis bhi choices m se longest lcs mili vo return hojaega
//             t[n][m] =   max(solve(text1, text2, n-1, m), solve(text1, text2, n, m-1));
//         }
//         return t[n][m];
// }
    int longestCommonSubsequence(string text1, string text2) {
        //rec m last se elem ko compare krenge agar eq char mile to dono ki string size -1 karke ek char count kr by doing +1 kr lenge ek common mil gya 
        //agar nhi mila to 2 choices 
        //1st string ki size -1 karo 2nd ki same rhnedo
        //2nd string ki size -1 karo , 1st string ki same rhnedo
        //recursive 
        
        int n = text1.size();
        int m = text2.size();
        // memset(t, -1, sizeof(t));
        // return solve(text1, text2, n , m);
//iterative
vector<vector<int>> dp(n+1, vector<int>(m +1, -1));
for(int i =0; i<= n ; i++){
  dp[i][0] =0;
}
for(int j =0; j<= m; j++){
  dp[0][j] =0;
}
   for(int i =1; i<=n; i++){
    for(int j =1; j <= m ; j++){
        if(text1[i-1] == text2[j-1]){
            dp[i][j] = dp[i-1][j-1] +1;
        }else{
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
   }   
   return dp[n][m];  
    }
};