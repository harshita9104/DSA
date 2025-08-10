class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        stk.push(-1);
        int ans = 0;
        //Here the approach is nothing but we are using a stack and when we encounter an opening brace then we push the index of it into the stack and whenever we touch a closing brace then we see the top of the stack if it's size is one then it means the closing braces have dominated the opening brace. We then edit the top value of the stack to the index of the closing brace.
        for(int i = 0 ; i < s.size();  i++)
        {
            if(s[i] == '(')
                stk.push(i);
            else
            {
                if(stk.size() == 1)
                    stk.top() = i;
                else
                {
                    stk.pop();
                    ans = max(ans , i - stk.top());
                }
            }
        }
        return ans;
    }
};