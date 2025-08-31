Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104

  

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        // dp[i][j] will be true if there is a subset of first i elements with sum j
        int dp[n+1][sum+1];

        // Base Case Initialization:
        // 1. If sum is 0, answer is always true (empty subset)
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        // 2. If no elements and sum > 0, answer is false
        for(int j = 1; j <= sum; j++) {
            dp[0][j] = false;
        }
        
      //dp ki table m har ek cell ke sub problem ko represent karta h 
        //dp[i][j] ka mtlb agar arr m i elem hote or sum j hota to answer kya aata 
        //Because the ith item in DP means arr[i-1] in the array.
// And for the subproblem of sum j, you need to check if this item can be included (arr[i-1] <= j).
         for(int i = 1; i<=n; i++){
            for(int j =1; j <= sum; j++){
                //dp ka ith elem arr k i-1th elm se matched hai kyuki i ka mtlb arr ki size se hai jab i =0 hai to mtlb arr m 0 elem hai 
                //jab i = 1 hai to mtlb arr[0] elem hi h sirf isliye i refers to i-1 index tak k elem in arr 
                if(arr[i-1] <= j){
                    //since i referes to i-1)th index wala elem isliye j m se arr[i-1] sub kiya
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];//agar arr ka ye wala elem < sum h to , isko le bhi skte nhi bhi le skte, dono chocies m se agar ek n bhi true return kiya to yha par true aayega
                    //i-1 mtlb is elem ko process kr lia , j-arr[i] mtlb is elem ko subarr m consider kr lia to ab remaining sum jo find karna hai  vo sum-arr[i]
                }else{
                    dp[i][j] = dp[i-1][j];//is elem ko subarr m consider nhi kr skte kyuki iski val sum se jyada har par siko process kar lia to i-1 krenge
                }
            }
        }
        return dp[n][sum];
    }
};
      
