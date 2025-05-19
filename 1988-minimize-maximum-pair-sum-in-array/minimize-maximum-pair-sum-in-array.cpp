class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int h = n-1;
        // pair min with max and then move the pointers and pair 2nd with 2nd last and move on like this
        vector<int> pairsum(n/2);
        int i =0;
        while(l<h){
            pairsum[i] = nums[l] +nums[h];
            l++;
            h--;
            i++;
        }
        int sum = INT_MIN;
        for(int i =0; i<n/2; i++){
           sum = max(sum, pairsum[i]);
        }
        return sum;

    }
};