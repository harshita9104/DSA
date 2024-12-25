class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int closestsum = 100000;
//kyuki 3 no. consider krne hai har baar
        for(int k = 0; k<= n-3 ; k++){
            int i = k+1;
            int j = n-1;
            while(i<j){
               
                int sum = nums[i] +nums[j] + nums[k];
                //agar currsum ka diff closestsum ab tak ka usse kam hai to closest sum ko update kardo currsum is closest
                if(abs(target-sum) < abs(target- closestsum)){
                    closestsum = sum;
                }
                 if(sum < target){
                  i++;
                } else if(sum > target){
                    j--;
                }else{
                    return sum;
                }
               
            }
        }
        return closestsum;
    }
};