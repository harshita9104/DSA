Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 103
0 ≤ target ≤ 103

  
class Solution {
  public:
//   int solve(vector<int> &arr, int n, int target) {
//     // Base case: if target is 0, we've found a valid subset
//     if (target == 0) return 1;
//     // If no elements left and target is not 0, no valid subset
//     if (n == 0) return 0;
//     // If current element can be included
//     if (arr[n-1] <= target) {
//         // include it OR don't include it
//         return solve(arr, n-1, target-arr[n-1]) + solve(arr, n-1, target);
//     } else {
//         // can't include, only option is do not include
//         return solve(arr, n-1, target);
//     }
// }
    int perfectSum(vector<int>& arr, int target) {
    //is q m choice diagram bnega empty subarr se shuru karenge har ek elem par descision hoga 
    //ki lena h ya nhi lena, jab subset mil jae jiska sum hai tagrget k eq to usko count krke aage or 
    //explore karna hai ki , dusri choices se or bhi subsets bnenge kya
    //subset sum problem m true return kr dete the yha par 1 return krenge or usko add kr denge 
    //yani jitne aese subsets exist krte h unka sum karna h to 
    // subste sum problem m || use kiya tha kyuki vha true return krna tha yha par uski jagah + hoga
    //or initialisation m true ki jagah 1 or false ki jagah 0
    //jab sum =0 hai to hmesha true = 1 hai kyukli empty subset to ban hi skta
    //or jab elem 0 hai to koi bhi sum possible nhi 
    int n = arr.size();
    int dp[n+1][target+1];
    // along the columns  j aata hai sum se denote hoga
    //along the rows i aata hai , which is size of arr
    //initialisation
    for(int i =0; i<=n; i++){//change to i ho rha to j =0 hoga
        //isme agar j =0 hai it means sum =0 hai to hmesha true hoga
        dp[i][0] = 1;
    }
    for(int j = 1; j<= target; j++){
        dp[0][j] = 0;
    }
    
    for(int i =1; i<=n; i++){
        for(int j = 0; j<=target; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
   
    // return solve(arr, n , target);
        
    }
};
