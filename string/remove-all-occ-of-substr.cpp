//Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

string removeOccurrences(string s, string part) {
        //jab tak string ki length not equal to 0 h and vo part present h str m 
        //yani hmare part ki left occ str ki last index se kamm h
        //s.find() returns  1st occurence of the sequence we are looking for
        //s.find(part) this would check the part we are looking for is present in str or not
        while(s.length()>0 && s.find(part) < s.length()){
            s.erase(s.find(part) , part.size());
//us part ko erase kardo by passing 1st ind of part and part size in s.erase


        }
        return s;
    }