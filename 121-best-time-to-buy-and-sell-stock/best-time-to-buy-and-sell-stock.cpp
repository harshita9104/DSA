class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int n = prices.size();
        int low = prices[0];//initially lowest profit ko 1st elem lelo phir jaise traverse kr rhe arr m agar koi or smaller elem mila to usko low lelena 
        int max_profit = 0;//max_profit ko start m sabse least 0 lelo
        for(int i = 0; i<n; i++){
            if(prices[i] <low){
                low = prices[i];
                
            }else{
                // har elem par max_profit nikaalo loop k end m sabse max hi store hoga max_profit m 
                max_profit = max(max_profit, prices[i] - low);
            }
        }
    return max_profit;   
    }
};