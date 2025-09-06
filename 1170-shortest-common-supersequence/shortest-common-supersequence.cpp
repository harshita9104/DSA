class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Goal: Merge str1 and str2 to get the shortest string that contains both as subsequences
        // Both strings' order should be maintained in the merged string
        
        int n = str1.size(); // length of str1
        int m = str2.size(); // length of str2

        // Step 1: Build LCS table
        // dp[i][j] will store the length of the longest common subsequence between str1[0...i-1] and str2[0...j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1,0)); // initialize dp table with 0

        // Fill the dp table using classic LCS logic
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]){
                    // If current characters match, LCS increases by 1 (take diagonal + 1)
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    // If not matching, take max of ignoring one char from either string
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // Step 2: Backtrack from dp[n][m] to build the shortest common supersequence
        // Start from end of both strings and build the answer string in reverse
        string ans; // will store the result

        int x = n; // pointer in str1
        int y = m; // pointer in str2

        // Keep going until one of the strings is fully traversed
        while(x > 0 && y > 0){
            if(str1[x-1] == str2[y-1]){
                // If current characters match, include only once in answer and move diagonally up (both pointers --)
                ans.push_back(str1[x-1]);
                x--;
                y--;
            } else if(dp[x-1][y] > dp[x][y-1]){
                // If moving up in dp table gives longer LCS, include str1[x-1] and move pointer in str1
                ans.push_back(str1[x-1]);
                x--;
            } else {
                // Otherwise, moving left gives longer/equal LCS, include str2[y-1] and move pointer in str2
                ans.push_back(str2[y-1]);
                y--;
            }
        }

        // After exiting main loop, if any characters remain in str1, add them to answer
        while(x > 0){
            ans.push_back(str1[x-1]);
            x--;
        }

        // If any characters remain in str2, add them to answer
        while(y > 0){
            ans.push_back(str2[y-1]);
            y--;
        }

        // Since we built the answer string in reverse order, reverse it before returning
        reverse(ans.begin(), ans.end());

        // Final merged string contains both str1 and str2 as subsequences, with minimum possible length
        return ans;
    }
};