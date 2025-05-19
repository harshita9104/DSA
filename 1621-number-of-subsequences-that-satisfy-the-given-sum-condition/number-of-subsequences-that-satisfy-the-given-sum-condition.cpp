class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int M = 1e9+7;
        int n = nums.size();
        //sort the arr so that u can eliminate the max of subseq from right side we will take min and max on both ends of arr and take their sum and check with target if the sum is less than target then the max and min elem in any subseq u take remains the less than the target so for each elem from min to max elem in arr there are two possibilities whether to include or not include it in subsequence 
        sort(nums.begin(), nums.end());
        //is the sum of min and max is more than target it means the max elem need to be eliminated from the subseq as any elem after min adding to the curr max will only inc the sum so we have to do h--
        vector<int> power(n);//this stores power as pow function in c++ lead to TLE so we will precompute the power ourselves
        power[0] =1;
        
        for(int i = 1; i<n ; i++){
            power[i] = (power[i-1]%M*2)%M;
        }
        int l = 0; 
        int h = n-1;
        int result = 0;
        while(l<=h){
            if(nums[l] +nums[h] <= target){
                result = (result%M + power[h-l])%M;
                l++;
            }else{
                h--;
            }
        }
        return result;
    }
};