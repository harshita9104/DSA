class Solution {
public:
int profit = 0;

int helper(int index, bool buy, vector<int> &prices, int n,  vector<vector<int>> &dp){
    //jab arr khtm ho jae, tabb or kuch sell nhi kr skte
    // to profit 0 hoga us rec call m jisme index == n hua
    if(index == n)return 0;
    if(dp[index][buy] != -1)return dp[index][buy];
    if(buy){
        //it means i can buy now and next time i have to sell so i will make this bool buy=0
        //i have two choices whether to buy now or not, jisse max profit aaya vo rakhenge
        dp[index][buy] = max(-prices[index] + helper(index+1, 0, prices, n, dp), helper(index+1, 1, prices, n, dp));
    }else{
       dp[index][buy] = max(prices[index] + helper(index+1, 1, prices, n, dp), helper(index+1, 0, prices, n, dp));
    }
    return dp[index][buy];
}
    int maxProfit(vector<int>& prices) {
        //we need to buy stock on each localmin and sell it after that only we can buy again
        // so at each daya there is a possibility if i have already bought anything then i can either sell it or not sell it on next day
        //similarly if i have sell a prod then on next day i can either buy or sell
        //so whenever we have choices we think of recursion
        //profit is sum of all the sell - sum of all the buy
        //so when i will buy anything i am adding -prices[i] to my profit
        //and when i am adding:  +prices[i] to my profit
        // and i will keep a flag to decide what to do next 
        // lets say if that flag is 1 it means i can buy 
        //and if that flag is 0 it means i can sell
        //a helper func to keep a track of indexes and this buy flag
      int n = prices.size();
      vector<vector<int>> dp(n, vector<int>(2, -1));
      return helper(0, 1,prices, n, dp);
       
        
    }
};