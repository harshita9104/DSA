//You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
string removeDuplicates(string s) {
        int i =0;
        while(i<s.size()){
            if(s[i] == s[i+1]){
                s.erase(i,2);
//mistake- we need to start from beginning if we are erasing 2 elem to check if now from beginning do we find one more pair of adj duplicates or not
                i = 0;
            }else{
                i = i+1;
            }
        }
        return s;
    }

    //solution using stack


    
    string removeDuplicates(string s) {
        //initialise a result string 
        string result = "";
        //this loop iterate over each character c in sthe string s
        for(char &c : s){
            //result.length() != 0 is same as result.size()
            //result.size() check if string is not empty
            //result.back() returns the last char in string 
            //check if current char is eq to last char in result str
            if(result.size() && c == result.back()){
                //true, it means there is an adjacent duplicate, so res.pop_back() removes the last character from res
                result.pop_back();
            }else{
                result.push_back(c);
            }
        }
        return  result;
    }