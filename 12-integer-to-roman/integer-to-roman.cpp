class Solution {
public:
    string intToRoman(int num) {
        // These are all Roman numeral symbols, including subtractive forms like "IV", "IX", etc.
        // The order matters! Start from largest to smallest to subtract largest values first.
        vector<string> symbols = {
            "M",  // 1000
            "CM", // 900
            "D",  // 500
            "CD", // 400
            "C",  // 100
            "XC", // 90
            "L",  // 50
            "XL", // 40
            "X",  // 10
            "IX", // 9
            "V",  // 5
            "IV", // 4
            "I"   // 1
        };

        // Corresponding integer values for each Roman symbol above
        vector<int> values = {
            1000, 900, 500, 400, 100, 90,
             50,  40,  10,   9,   5,  4, 1
        };

        // This string will store the final Roman numeral result
        string result;

        // Go through each value-symbol pair from highest to lowest
        for (int i = 0; i < values.size(); i++) {
            // Keep using the current Roman symbol as long as its value fits in 'num'
            while (num >= values[i]) {
                result += symbols[i]; // Add the Roman symbol to the result
                num -= values[i];     // Subtract the corresponding value from the number
            }
        }

        // Once all values are subtracted and Roman symbols added, return the result
        return result;
    }
};
