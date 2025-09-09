Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.

Build the LCS table: Find out which characters are common and their positions.
Backtrack from the end: Build the shortest supersequence by including characters from both strings, picking the common ones only once.
Add leftovers: If one string is not finished, add the remaining characters.
Reverse the result: Because you built the answer from the end (right to left).
Return: The final shortest common supersequence.

1. Why LCS characters only once?
LCS (Longest Common Subsequence) is the sequence of characters that appears in both strings in the same order.
In SCS, when we hit a cell where str1[i-1] == str2[j-1],
that character is common in both, so we add it only once.
This avoids duplicating the common part.
2. What if characters are different?
When str1[i-1] != str2[j-1],
we have two choices:
Move left (add str2[j-1])
Move up (add str1[i-1])
The DP table tells us which move will result in a longer LCS.
If moving up (dp[i-1][j] > dp[i][j-1]),
add str1[i-1]
Else if moving left (dp[i][j-1] >= dp[i-1][j]),
add str2[j-1]
3. Why does this merge both strings?
Key Point:
Even though we only add one character at each step when the characters are different,
the backtracking process covers all positions of both strings.
When you reach the end (i = 0 or j = 0),
you add all remaining characters of the unfinished string.
This way, every single character of str1 and str2 is included somewhere in the final SCS.
4. Detailed Example
Let’s take your example:
str1 = "abac"
str2 = "cab"

DP Table is built. Now backtracking:

Start at cell (4, 3) (end of both strings).
If str1[i-1] == str2[j-1], add that character once and decrement both.
If not, check which direction gives longer LCS and add that character.
Continue until either string is finished, then add remaining characters.
What happens if both chars are different?

Suppose at some point, str1[i-1] = 'x', str2[j-1] = 'y' (not equal).
If DP says move up, add 'x' and move up.
If DP says move left, add 'y' and move left.
You never skip any character from either string, because at the end, you add leftovers from both strings.
5. Why not add both at once when different?
If you add both at once,
you’d sometimes duplicate, and the result would be longer than necessary.
Backtracking with DP ensures:
All characters are included
Common characters are merged
Sequence order from both strings is maintained
Result is shortest possible supersequence


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
