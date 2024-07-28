//Given a string of balanced expression str, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Return 1 ifit contains a redundant parenthesis, else 0.
// Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

// Example 1:

// Input:
// exp = ((a+b))
// Output:
// Yes
// Explanation:
// ((a+b)) can reduced to (a+b).
// Example 2:

// Input:
// exp = (a+b+(c+d))
// Output:
// No
// Explanation:
// (a+b+(c+d)) doesn't have any redundant or multiple
// brackets.

//is q  m expression m they dont consider alphabets to alphabets ko ignore karo

int checkRedundancy(string s) {
        stack<char> st;
        for(int i = 0; i< s.size(); i++){
           if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                st.push(s[i]);
            }
//Basically in my solution i am just focusing on operator and brackets rather than alphabets , so that's why in this i am just going continue when i encounter any alphateic character 

            else if (s[i] >= 'a' && s[i] <= 'z'){
                continue;
            }else if (s[i] >= 'A' && s[i] <= 'Z'){
                continue;
            }
            else{
                //when char is a closing bracket 
                if(st.top() == '('){
 //agar closing bracket hai current char or stack k top p abhi 
  //opening bracket hai it means there is no expression bw them and they are redundant
                    return 1;
                }else{
                    while(st.top() != '('){
                        st.pop();
                    }
                    st.pop();
                }
            }
        }
        return 0;
    }