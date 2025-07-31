class Solution {
public:
    bool isValid(string curr){
        //to test whether a string is valid or not just check if the no of close brackets fully cancels out open bracket or not u can use a stack  so that push only open bracket inside stack, and if u see a close bracket pop from stack in the end the stack shd be empty
        //u can use a count var also
        int count = 0;
        int open = 0;
        int close =0;
        for(char &ch: curr){
            if(ch == '('){
            count++;
            open++;
            }else {
            count--;
            close++;
            }
            if(close> open)return false;
        }
        if(count == 0)return true;
        return false;
    }
    void solve(string curr, int n, vector<string> &result){
        if(curr.size() == 2*n){
            if(isValid(curr))
            result.push_back(curr);
            return;
        }
        //since at each step we will have 2 options either insert ( bracket in string OR insert ) in string so we will follow backtracking principal
        //we will first push a bracket in string call recursion for that cur string to explore if it gets a valid curr string with this choice and then undo this choice means pop_back from curr 
        //so that we can explore second choice as well and
        //backtracking works on - do -> explore ->undo

        curr.push_back('(');
        solve(curr, n, result);
        curr.pop_back();
        curr.push_back(')');
        solve(curr, n , result);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve("",n,result);
        return result;
    }
};