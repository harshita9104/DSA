class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxprofit =INT_MIN;
        int currsum =0;
        // for(int start = 0; start<n; start++){
        //     int currsum =0;//jaise hi starting point change ho rha currsum =0 krdo
        //     for(int end = start ; end<n; end++){
        //        currsum += nums[end];
        //        maxprofit = max(maxprofit, currsum);
        //     }
        // }
        //ek hi loop chalao jaise hi sum neg ho hm usko aage carry nhi krenge sum =0 kr denge it means we are starting new subarr from next elem 
        for(int i = 0; i<n; i++){
            currsum += nums[i];
             maxprofit = max(maxprofit, currsum);
             if(currsum<0){
                currsum =0;
             }
        }
        return maxprofit;
    }
};