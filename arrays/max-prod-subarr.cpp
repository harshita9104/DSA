// Given an integer array nums, find a 
// subarray
//  that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

long long maxProduct(vector<int>& nums) {
        //mistake intialise maxprod to 1 ....max shd have INT_MIN initially so that anything compared to it returns max
        // since the prod can be neg or 0 so comparing with maxprod shd give that value only, not 1
        long long maxprod = INT_MIN;
        long long currprod = 1;
        int n = nums.size();
        for(int i =0; i<n; i++){
            
            currprod *= nums[i];
            maxprod = max(maxprod, currprod);
            if(currprod==0){
                currprod=1;

            }
        }
        
        //mistake reinitialise it to 1 before traversing right to left
        currprod = 1;
        for(int j = n-1; j>=0; j--){
            //mistake ho skta h aage jaake neg*neg hoke pos ho jae
            // if(currprod <0 && nums[i]>0){
            //     currprod = 1;
            
            currprod *= nums[j];
            maxprod = max(maxprod, currprod);
            if(currprod==0){
                currprod=1;

            }
            
       
    }
    return maxprod;
    }     
