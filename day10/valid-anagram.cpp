//Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        //declare a hash arr of 26 size to store the freq of each char in s
        int count[26] = {0};
        for(int i = 0; i<s.length(); i++){
            //find the position of char it will be index of count arr
            int index = s[i] - 'a';
            count[index]++;


        }
        //now traverse through 2nd string to check the char in it occur the same no. of times as in str1.
        for(int i = 0; i<t.length(); i++){
            int idx = t[i] - 'a';
            //if a char present in str2 is not present in str1 return false
            if(count[idx] == 0 ){
                return false;
            }
            //so that if any letter is occuring more no. of times in str2 and if its count becomes 0 it will return false.
            count[idx]--;
        }
        return true;
    }
};