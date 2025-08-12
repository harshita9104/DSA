class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
//iterate through the Roman numeral string from right to left, converting each symbol to its corresponding integer value. If the current symbol has a smaller value than the symbol to its right, we subtract its value from the result; otherwise, we add its value to the result. By processing the string from right to left, we can handle cases where subtraction is required (e.g., IV for 4) effectively.
        int result = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int currValue = romanValues[s[i]];

            if (i < s.length() - 1 && currValue < romanValues[s[i + 1]]) {
                result -= currValue;
            } else {
                result += currValue;
            }
        }

        return result;
    }
};