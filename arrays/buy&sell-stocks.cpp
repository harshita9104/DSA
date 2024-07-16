//TLE error 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxprofit = 0;
        int n = prices.size();
        for(int i = 0; i<n ; i++){
            int minbuy = prices[0];
            for(int j = 0; j<i; j++){
                if(minbuy > prices[j]){
                    minbuy = prices[j];
                }
            }
            profit = prices[i] - minbuy;
            maxprofit = max(profit, maxprofit);

        }
        return maxprofit;
    }
};

//optimal code
class Solution {
    public int maxProfit(int[] prices) {
        int buy = prices[0]; // Initialize buy to the first day's price
        int profit = 0;      // Initialize profit to 0
        
        // Iterate over the prices array starting from the second day
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < buy) {
                // If the current price is lower than the buy price, update buy price
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                // If the current profit is higher than the previous maximum profit, update profit
                profit = prices[i] - buy;
            }
        }
        
        // Return the maximum profit found
        return profit;
    }
}
