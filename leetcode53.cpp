//Given an integer array nums, find the  subarray  with the largest sum, and return its sum.
// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
//brute force 
//starting from an index and consider including next element in each iteration and calculating the sum for each subarray and checking if it is max , and then again starting from next index in next iteration 
 int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = INT_MIN;
        for(int i = 0; i<n ; i++){
          //take sum as 0 whenever starting the subarr from a new index
            int sum = 0;
            for(int j = i ; j<n ; j++){
                sum += nums[j];
                 maxsum = max(maxsum, sum);
                
            }
        }
        return maxsum;

        //kadane's algo
        //if the sum<0 after any inner teration we dont carry this sum, we first reduce this sum to 0  and then add next element to it and everytime we compare sum with max and if it is more than max we replace max with new sum
        int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            //mistake 
            //calculate maxsum before making the currentsum as 0 becoz suppose if the arr contain only negative elements then it will reduce the sum to 0 but in that case the answer ie, maxsum shd be the neg sum rather than 0 so the output would become wrong.
             maxsum = max(maxsum, sum);
            if(sum<0){
                sum = 0;
            }
        
        }
          return maxsum;
        }