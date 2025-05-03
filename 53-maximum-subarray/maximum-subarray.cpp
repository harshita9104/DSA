class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //brute force app

        int max_sum = INT_MIN;
        int n = nums.size();
        // for(int start = 0; start<n; start++){
        //     for(int end = start; end<n; end++){
        //         int cursum = 0; //start or end jab change ho rha it means naya subarr le rhe to currsum 0 kardo
        //         for(int i = start; i<=end; i++){
        //             cursum += nums[i];
        //             max_sum = max(max_sum, cursum);
        //         }
        //     }
        // }
        // return max_sum;
//in above method hm same start point se jitni bhi subarr h un sab ka sum baar baar scratch se cal kr rhe h isko optimise kr skte
        //jin subarr ka start pt same h usme bas ending elem add krte jaao ek ek karke
        //or jaise hi naya starting point aayega curr sum ko 0 se initialise krenge
        // for(int start = 0; start<n; start++){
        //     int cursum = 0;
        //     for(int end = start ; end<n; end++){
        //         cursum += nums[end];
        //         max_sum = max(max_sum, cursum);
        //     }

        // }
        // return max_sum;

        //optimised app - kadane's algo
        //ek hi loop  chlao jaise hi sum neg ho jae usko 0 kardo
        int sum = 0;
        for(int i = 0; i<n ; i++){
            sum += nums[i];
                max_sum = max(max_sum, sum);
                if(sum<0){
                    sum = 0;
                }
            }
             return max_sum;

    }
};