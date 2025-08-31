Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

Examples:

Input: arr[] = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
Hence, minimum difference is 1.  
Input: arr[] = [1, 4]
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4
Hence, minimum difference is 3.
Input: arr[] = [1]
Output: 1
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {}, sum of Subset2 = 0
Hence, minimum difference is 1.
Constraints:
1 ≤ arr.size()*|sum of array elements| ≤ 105
1 <= arr[i] <= 105





  class Solution {
 //recursive soln hai subset1 ka sum calculate krenge - ye tle dega
      //last se arr ko traverse krenge or  elem ko subset1 m daalna h ya nhi ye 2 choices hogi agar daaldiya to 
      //arr[i] ko subset1sum m add krdo
      //nhi daala to mat kro 
      //subset2 sum = totalsum - subset1sum
      //jab sare elem process ho jae yani base case reach ho jae , tab abs(subset2sum- subset1sum) return krdo
      //2 choices hai to 2 baar rec call hoga dono base case par reach hoke abs diff leke aayega or vo 2 integer include or exclude mai laake rakh dega
      //ab in dono m se jo min hoga vahi return krna h
  public:
//   int t[101][10001]; // Memoization table (adjust size based on constraints)- top down

//     int solve(std::vector<int>& arr, int n, int subset1sum, int sumtotal) {
//         // Base case: If no elements are left, calculate and return absolute difference
//         if (n == 0) {
//             return abs((sumtotal - subset1sum) - subset1sum);
//         }

//         // If already solved for this state, return the stored result
//         if (t[n][subset1sum] != -1) {
//             return t[n][subset1sum];
//         }

//         // Include current element in subset1
//         int include = solve(arr, n-1, subset1sum + arr[n-1], sumtotal);
//         // Exclude current element from subset1
//         int exclude = solve(arr, n-1, subset1sum, sumtotal);

//         // Store and return the minimum of the two choices
//         return t[n][subset1sum] = std::min(include, exclude);
//     }

//     int minDifference(std::vector<int>& arr) {
//         int sumtotal = 0;
//         int n = arr.size();

//         // Calculate total sum of array
//         for (int i = 0; i < n; i++) {
//             sumtotal += arr[i];
//         }

//         // Initialize memoization table with -1
//         memset(t, -1, sizeof(t));

//         // Start solving with subset1sum = 0
//         return solve(arr, n, 0, sumtotal);
//     }
// };
//tabulate- bottom up
int minDifference(vector<int>& arr) {
    int n = arr.size();
    int sumtotal =0;
    for (int i = 0; i < n; i++) {
            sumtotal += arr[i];
        }
    // Initialize with default values (e.g., 0 for int)
    // vector<vector<int>> matrix1(rows,vector<int>(cols)); 
    //i need to create a 2d matrix that consist of 2 parameters that are changing in recursive solution and initialise all cells as 0 
    vector<vector<bool>> dp(n+1,vector<bool>(sumtotal+1, false));//intialised to false all cells
    //now in this approach we will iterate and fill this table each cell is subproblem 
    //this dp table will store that dp[i][j], ia a subset possible  from arr  with i elem in arr and j as sum of subset
    //since sum of 0 is always achievable by empty subset so 1 subset so initialise whole col of sum =0 as true 
    //since sum of 0 is always achievable so we mark which is true
    
    for(int i =0; i<= n; i++){
        dp[i][0] = true;
    }
    for(int i =1; i<=n; i++){
        for(int j = 1; j<= sumtotal; j++){
           //this table is similar to subset sum problem table 
            //since both are choices  we use or between them if any choice return true then it means subset is possible so true
           if(arr[i-1] <= sumtotal){
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
           }else{
               dp[i][j] = dp[i-1][j];//cant include this elem in subset
           }
        }
    }
    //table fill ho gyi ab arr size = n wali row ko iterate kro 
    //usme jitne sum possible hai yani cell ki value true h vo subsetsum1 ki ek possible value ho skti hai 
    //us value se mindiff nikal skte
    int mindiff = INT_MAX;
    for(int subsetsum1 = 0; subsetsum1 <= sumtotal/2; subsetsum1++){
        if(dp[n][subsetsum1] == true){
            mindiff = min(mindiff, abs((sumtotal-subsetsum1) - subsetsum1));
        }
    }
    return mindiff;
}
};
