// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

#include <bits/stdc++.h>
using namespace std;

void solve(string s, string op, vector<string> & result){
        if(s.empty()){
            //since we have to return result in the end so push the op in it.
            result.push_back(op);
            return;
        }
        
//if the input is alphabet we have two choices to include it in op in lowercase or upper case
         //in c++ to check whether the input is alphabet or not isalpha();
         if(isalpha(s[0])){
            string op1 = op;
        string op2 = op;
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            s.erase(s.begin());
            solve(s, op1, result);
            solve(s, op2, result);
        }else{
            //if the ip is digit we have to include it only
            // we have only one choice so no need of 2 op strings 
            string op1 = op;

            op1.push_back(s[0]);
            s.erase(s.begin());
            //the recursive functioon need to be called only once as only one node is present 
            solve(s, op1, result);
            

         }
         

    }
    vector<string> letterCasePermutation(string s) {
        string op = "";
        vector<string> result;
        solve(s,op, result);
        return result;
    }