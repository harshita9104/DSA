// Given a string s, you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings.

// Example 1:

// Input:
// s = "ABC"
// Output: (A B C)(A BC)(AB C)(ABC)
// Explanation:
// ABC
// AB C
// A BC
// A B C
// These are the possible combination of "ABC".

// ip -op , recursive tree app
#include<iostream>
#include <bits/stdc++.h>

#include <string>

using namespace std;

//mistake -not including & before resullt in parameters 
    void solve(string s, string op,vector<string> &result ){
        if(s.length() == 0){
            result.push_back(op);
            return;
            //mistake
            // return result;
        }
       
        //as the output is continued for the smaller input we have two choices
        string op1 = op;
        string op2 = op;
        //1st , to include the 0th index elm of our new ip string with space or without space
        op1.push_back(' ');
        op1.push_back(s[0]);
        op2.push_back(s[0]);

        //since we have taken decision for  0th index elem of our string
        //erase it from input to make the input smaller
        //s.begin places an iterator at begininng
        s.erase(s.begin() + 0);

        //now recursively call the solve fun for smaller input and each new op
        solve(s, op1,result);
        solve(s, op2, result);
        
    }
    vector<string> permutation(string s) {
        vector<string> result;
        string op = "";
         //since there is no choice with the 1st elem of str we need to include it without space
        //mistake -dont write this initial string elem in op in recursive function as it is only for the first elem 
        op += s[0];
        //now erase this elem and call our recursive function with new ip and op containing the first elem of string which was to be included in all the results without space
        s.erase(s.begin()+0);

        solve(s, op, result);
        return result;
        
        
        
    }
    int main(){
  string s = "ABC";
  // string op ="";
  permutation(s);
  return 0;
}