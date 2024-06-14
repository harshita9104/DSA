//You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

// Example 1:

// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
// Example 2:

// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
// Example 3:

// Input: letters = ["x","x","y","y"], target = "z"
// Output: "x"
// Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letter[0].
 
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //we have to find ceil of the target but that shouldnt be eq to target
        int low = 0;
        int high = letters.size() -1;
        //mistake - take initial char that has the max ascii value 
        char result = 'z';
        //mistake - if target is last elem in letters then no elem greater than this is present in letters so return letters[0] 
        if(letters[0] >target || target >= letters[letters.size() -1]){
            return letters[0];
        }
        while(low<= high){
            int mid = low+(high - low)/2;
            if(letters[mid] == target){
                low = mid+1;

            }else if(letters[mid]< target){
                low = mid +1;

            }else if(letters[mid]> target){
                //mistake - we need the smallest elm > target so take min of the result 
                //we have temp stored letter[mid] as this can be a possible answer but a smller elem can also exist which is> target
                result = min(result,letters[mid]);
                high = mid-1;
            }

        }
        return result;
    }
};
