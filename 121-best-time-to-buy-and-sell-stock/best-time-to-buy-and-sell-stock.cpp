class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int n = prices.size();
    //     int low = prices[0];//initially lowest profit ko 1st elem lelo phir jaise traverse kr rhe arr m agar koi or smaller elem mila to usko low lelena 
        int max_profit = 0;//max_profit ko start m sabse least 0 lelo
    //     for(int i = 0; i<n; i++){
    //         if(prices[i] <low){
    //             low = prices[i];
                
    //         }else{
    //             // har elem par max_profit nikaalo loop k end m sabse max hi store hoga max_profit m 
    //             max_profit = max(max_profit, prices[i] - low);
    //         }
    //     }
    // return max_profit; 


    //stock ko buy karna jaruri hai sell krne se phle or buying or selling different days par honi chahiye
    //assume tht we can sell everyday or har din k liye best possible buying price nikaal lo
    //yani current day ser phle ka koi din hona chahiye jis din price min val par ho
    //best buy price nikalne k liye usse phle k ek din tak hi consider kro
    vector<int> BestBuy(n);
    BestBuy[0] = prices[0];
    for(int i = 1; i<n ; i++){
       BestBuy[i] = min(BestBuy[i-1], prices[i]);
    }
    //assuming each day to be selling day
    vector<int> profit(n);
    for(int i =0; i<n ; i++){
        profit[i] = prices[i] - BestBuy[i];
        max_profit = max(max_profit, profit[i]);

    }
    return max_profit;
    }
};