class Solution {
public:
    int numDecodings(string s) {
        // edge cases out - leading zero and single character string
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        // support variables
        //First of all we need to check for an annoying edge cases - a leading '0', which is not valid and if so we just return 0 combinations; similarly, any other single character (ie: other than '0', since we put the second condition after that check) will always mean just 1 combination.
        int len = s.size(), dp[3];
        // preparing dp
        dp[0] = 1;
        dp[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');
        for (int i = 2, curr, prev; i < len; i++) {
            curr = i % 3;
            prev = curr ? curr - 1 : 2;
            // edge case: we quit for 2 consecutive zeros
            if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0')) return 0;
            // base case: we always keep the previous set of combinations, unless we met a 0
            dp[curr] = s[i] != '0' ? dp[prev] : 0;
            // we go and look 2 positions behind if we can make a digit in the 10-26 range
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') dp[curr] += dp[prev ? prev - 1 : 2];
        }
        return dp[(len - 1) % 3];
    }
};