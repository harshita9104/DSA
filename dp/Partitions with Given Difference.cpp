Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples :

Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Input: arr[] = [1, 1, 1, 1], d = 0 
Output: 6 
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 
Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2
Constraint:
1 <= arr.size() <= 50
0 <= d  <= 50
0 <= arr[i] <= 6



class Solution {
public:
    int subsetsum(vector<int>& arr, int targetsum, int n) {
        // Create a DP table
        vector<vector<int>> dp(n + 1, vector<int>(targetsum + 1, 0));

        // Base case: There's always one way to achieve sum = 0 (by choosing an empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= targetsum; j++) {
                if (arr[i - 1] <= j) {
                    // Include or exclude the current element
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                } else {
                    // Exclude the current element
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Return the number of subsets that achieve the target sum
        return dp[n][targetsum];
    }
 //s1-s2 = d
        //s1+ s2 = total sum
        //so s1 = (total sum+d)/2
        // i just need to find whether a subset of sum s1 exist in the arr or not 
        //so if s1 exists then the other one will be s2 only 
        //so this problem became subset sum problem
    int countPartitions(vector<int>& arr, int d) {
        int totalsum = 0;
        int n = arr.size();

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totalsum += arr[i];
        }

        // Edge case: If (totalsum + d) is odd, or d > totalsum, no valid partition exists
        if ((totalsum + d) % 2 != 0 || d > totalsum) {
            return 0;
        }

        // Calculate the target sum (s1)
        int targetsum = (totalsum + d) / 2;

        // Count the subsets with sum equal to targetsum
        return subsetsum(arr, targetsum, n);
    }
};
