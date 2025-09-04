You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1


//top down- iterative 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //we need to return no of ways it means no of subsets that has its sum equal to given amount so we will add up all our choices
        //and since ek coin ko kitni bhi baar select kr skte 
        //jisko selct kar liya usko process nhi krenge
        //unbounded knapsack
        //in intialisation
        //agar kuch choices kari jinko select kiya unki value ko amount se subtract kr lia or if sum =0  ho gya it means we have got onw subset put 1
        //or agar coins sare process ho gye that means size of arr 0 ho gyi or sum 0 nhi hua it means subset nhi mila put 0 in it
        //col will represent amount
        //rows will rep size of arr
        int n = coins.size();
        vector<vector<long long>> dp(n+1, vector<long long>(amount+1));
        for(int j =0; j<= amount; j++){
            dp[0][j] = 0;
        }
        for(int i =0; i<= n; i++){
            dp[i][0] = 1;//sum =0 ka empty subset is always possible
        }

        for(int i =1; i<=n; i++){
            for(int j =1; j<= amount; j++){
                if(coins[i-1] <= j){
                    //is coin ko include exclude dono kr skte jha bhi subset mila vo 1 leke aa rha hoga to add up ho jaega, choices add krdo
                    //jisko le liya subset m usko dobara bhi le skte process mt kro
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }else{
                    //isko nhi le skte to isko process kr lenge
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};

//bottom up- memoization - Your memoized recursion worked because it only explores reachable states, avoiding redundant or unreachable computations, so overflow is much less likely.
// The tabulated solution fills all possible states, causing huge intermediate values and overflow.


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
