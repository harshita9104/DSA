class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Edge case: If there's only one person and no trust relationships,
        // that one person is the judge by definition.
        if (trust.size() == 0) return n == 1 ? 1 : -1;

        // We use n+1 because people are labeled from 1 to n (not 0).
        vector<int> outdeg(n + 1, 0); // outdeg[i]: number of people i trusts
        vector<int> indeg(n + 1, 0);  // indeg[i]: number of people who trust i

        // Process each trust relationship
        for (const vector<int>& rel : trust) {
            int a = rel[0]; // a trusts b
            int b = rel[1];
            outdeg[a]++;    // a trusts someone, so increment out-degree of a
            indeg[b]++;     // someone trusts b, so increment in-degree of b
        }

        // The judge must be trusted by everyone else (in-degree == n-1)
        // and trusts nobody (out-degree == 0)
        for (int i = 1; i <= n; i++) {
            if (outdeg[i] == 0 && indeg[i] == n - 1) {
                // Found the judge
                return i;
            }
        }

        // No judge found
        return -1;
    }
};