You are given two strings s1 and s2. Your task is to print all distinct longest common subsequences in lexicographical order.

Note: A subsequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

Examples:

Input: s1 = "abaaa", s2 = "baabaca"
Output: ["aaaa", "abaa", "baaa"]
Explanation: Length of lcs is 4, in lexicographical order they are "aaaa", "abaa", "baaa".
Input: s1 = "aaa", s2 = "a"
Output: ["a"]
Explanation: Length of lcs is 1 and it is "a".
Constraints:
1 ≤ s1.size(), s2.size() ≤ 50


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

// Memoization table to store already computed LCS sets for (i, j)
set<string> memo[55][55];

// Function to build LCS DP table (bottom-up)
vector<vector<int>> buildDP(const string& X, const string& Y) {
    int m = X.size(), n = Y.size();
    // Create DP table of size (m+1) x (n+1) and initialize with 0
    vector<vector<int>> L(m+1, vector<int>(n+1, 0));
    // Fill DP table
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0 || j==0) 
                L[i][j]=0; // LCS length is 0 if any string is empty
            else if(X[i-1]==Y[j-1]) 
                L[i][j]=L[i-1][j-1]+1; // If chars match, increment LCS by 1
            else 
                L[i][j]=max(L[i-1][j],L[i][j-1]); // Otherwise, take max LCS of removing one char from either string
        }
    }
    return L; // Return filled DP table
}

// Recursive function to generate all LCS strings of length L[i][j]
set<string> allLCS(const string& X, const string& Y, int i, int j, const vector<vector<int>>& L) {
    // Base case: if either string is empty, only "" is possible
    if(i==0 || j==0) return {""};
    // If already computed for (i, j), return cached result
    if(!memo[i][j].empty()) return memo[i][j];

    set<string> res; // Set to store all LCS strings for this subproblem
  //Logic:
// You are at (i, j) in your DP table. If X[i-1] == Y[j-1], this character must be part of LCS.

// You now want to get all LCSs for the subproblem (i-1, j-1) (i.e., the LCSs up to the previous indices).

// For each such LCS (let's call it s), you append the current matching character (X[i-1]).

// This is because every LCS ending at (i, j) is made by taking all LCSs from (i-1, j-1) and adding the matching character.

// Why for loop?

// There may be multiple different LCSs of maximum length that reach this cell.
// Each LCS path can lead to a different string, so you need to collect all those possibilities.

    if(X[i-1]==Y[j-1]) {
        // If chars match, include that char in all LCSs from previous indices
        for(const string& s : allLCS(X,Y,i-1,j-1,L)) {
            res.insert(s + X[i-1]); // Append matching char to all LCSs found for (i-1, j-1)
        }
    } else {
//         // If not matching, check both possible directions Logic:
// Here, X[i-1] and Y[j-1] do not match.

// You look at your DP table: LCS could come either from removing last char of X (go to (i-1, j)), or removing last char of Y (go to (i, j-1)).

// You choose all directions that could possibly lead to the maximum LCS length.

// Why for loop?

// Because from (i-1, j) and (i, j-1), each can yield multiple LCSs of the same maximum length.
// You need to collect all possibilities to ensure no valid LCS is missed.
// Why >= and not just >?

// If both directions give the same LCS length, you must follow both, or you might miss some LCSs.

        if(L[i-1][j] >= L[i][j-1]) {
            // If removing one char from X gives LCS of same length, get all LCSs from (i-1, j)
            for(const string& s : allLCS(X,Y,i-1,j,L)) res.insert(s);
        }
        if(L[i][j-1] >= L[i-1][j]) {
            // If removing one char from Y gives LCS of same length, get all LCSs from (i, j-1)
            for(const string& s : allLCS(X,Y,i,j-1,L)) res.insert(s);
        }
    }
    // Store computed result for (i, j) in memoization table
    memo[i][j]=res;
    return res; // Return all LCSs for (i, j)
}

int main() {
    string X,Y;
    cin >> X >> Y; // Read both strings
    int m = X.size(), n = Y.size();
    // Build LCS DP table
    vector<vector<int>> L = buildDP(X,Y);
    // Clear memo table for current input
    for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) memo[i][j].clear();

    // Find all LCSs of maximum length
    set<string> lcsSet = allLCS(X,Y,m,n,L);
    int maxLen = L[m][n]; // Get LCS length
    vector<string> answer;
    // Only collect LCSs of maximum length
    for(const string& s : lcsSet) {
        if(s.size() == maxLen) answer.push_back(s);
    }
    sort(answer.begin(), answer.end()); // Sort in lexicographical order
    for(const string& s : answer) cout << s << "\n"; // Print each LCS
    return 0;
}
