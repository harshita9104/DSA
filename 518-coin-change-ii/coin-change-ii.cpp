// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         //we need to return no of ways it means no of subsets that has its sum equal to given amount so we will add up all our choices
//         //and since ek coin ko kitni bhi baar select kr skte 
//         //jisko selct kar liya usko process nhi krenge
//         //unbounded knapsack
//         //in intialisation
//         //agar kuch choices kari jinko select kiya unki value ko amount se subtract kr lia or if sum =0  ho gya it means we have got onw subset put 1
//         //or agar coins sare process ho gye that means size of arr 0 ho gyi or sum 0 nhi hua it means subset nhi mila put 0 in it
//         //col will represent amount
//         //rows will rep size of arr
//         int n = coins.size();
//         vector<vector<long long>> dp(n+1, vector<long long>(amount+1));
//         for(int j =0; j<= amount; j++){
//             dp[0][j] = 0;
//         }
//         for(int i =0; i<= n; i++){
//             dp[i][0] = 1;//sum =0 ka empty subset is always possible
//         }

//         for(int i =1; i<=n; i++){
//             for(int j =1; j<= amount; j++){
//                 if(coins[i-1] <= j){
//                     //is coin ko include exclude dono kr skte jha bhi subset mila vo 1 leke aa rha hoga to add up ho jaega, choices add krdo
//                     //jisko le liya subset m usko dobara bhi le skte process mt kro
//                     dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
//                 }else{
//                     //isko nhi le skte to isko process kr lenge
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         return dp[n][amount];
//     }
// };
//Your DP is likely counting the same combinations multiple times due to the order you fill your DP, especially when using a 2D DP.
// The "coin change combinations" problem should be solved with a 1D DP (not 2D) to avoid duplicate counting and overflow.
// In your approach, for large test cases, the number of combinations can exceed even long long during DP filling, even if the final answer is small.


class Solution {
public:
    int solve(int amount, vector<int>& coins,int sum,int &ans,int i,vector<vector<int>>&dp){
        if(i==coins.size() || sum>amount){
            return 0;
        }
        if(sum==amount)return 1;
        if(dp[i][sum]!=-1)return dp[i][sum];
        dp[i][sum]=solve(amount,coins,sum+coins[i],ans,i,dp)+solve(amount,coins,sum,ans,i+1,dp);
        return dp[i][sum];
    }
    int change(int amount, vector<int>& coins) {
        int ans=0;
        int sum=0;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(amount,coins,sum,ans,0,dp);
    }
};