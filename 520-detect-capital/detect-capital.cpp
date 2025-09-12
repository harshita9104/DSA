

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int capital_count = 0;

        // Count the total number of capital letters in the word
        for (char c : word) {
            if (isupper(c)) {
                capital_count++;
            }
        }

        // Now, check against the three valid rules:
        // 1. All letters are capitals ("USA") -> capital_count == n
        // 2. All letters are not capitals ("leetcode") -> capital_count == 0
        // 3. Only the first is capital ("Google") -> capital_count == 1 AND the first letter is a capital
        
        if (capital_count == n || capital_count == 0 || (capital_count == 1 && isupper(word[0]))) {
            return true;
        }

        // If none of the above rules match, the usage is wrong.
        return false;
    }
};