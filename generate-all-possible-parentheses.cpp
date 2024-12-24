// Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.


// Example 1:

// Input:
// N = 3
// Output:
// ((()))
// (()())
// (())()
// ()(())
// ()()()

#include<bits/stdc++.h>
//here u need to observe and decide choices in our recursive tree
    //1st we will get open bracket choice jab tak open bracket khtam n ho jae
    //u  cant start op string with a closed bracket as it wont be balanced paranthese
    //so 2nd cond would be ki closing bracket ki choice jab milegi tab close>open
    //tum close tab hi use kar skte ho jab phle hi extra open brackets use kr chuke ho
    //mtlb open bracket ki count < close  bracket ki count
    void solve(int open, int close, string op, vector<string> &result){
        //base case is when both the open and close has become 0
        if(open == 0 && close == 0 ){
            result.push_back(op);
            return;
        }
        //choice of using open bracket
        if(open != 0){
            string op1 = op;
            op1.push_back('(');
            //now reduce the count of open since we have put it in op
            //everytime we push a open bracket in op string its count reduce by 1
            solve(open-1, close, op1, result);
        }
        //choice of using closed bracket is based upon this cond which is indep of 1st cond so used if
        if(close> open){
            string op2 = op;
            op2.push_back(')');
            
            solve(open, close-1, op2, result);
        }
            
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> result;
        string op ="";
        int open = n;
        int close = n;
        solve(open,close, op, result);
        return result;
    }
