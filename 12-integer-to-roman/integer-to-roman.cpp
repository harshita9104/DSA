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

string result = "";
    for(int i = 0; i<symbols.size(); i++){
        int times = num/values[i];
        int val = 0;
        if(times>0){
            while(times--){
                result += symbols[i];
            }
            val +=values[i];
        }
        if(val != 0)num = num%val;
    }
    return result;
    }
};