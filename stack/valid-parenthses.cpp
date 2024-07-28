// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
 



 //observation :
        //har opening bracket k liye uske baad closing bracket exist krta h
        //jis seq m string m opening bracket hai uske opposite seq m closing brackets hai, to check karne k liye ki kisi closing bracket k liye uska coreesponding opening bracket phle str m aaya ya nhi uske liye hm stack ka use karenge kyuki stack m jis order m hm char daalenge uske opp order m vo bahar aayenge
        stack<char> st;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '(' ){
                st.push(s[i]);
                //jaise hi koi closing bracket milta hai to uska corresponding opening bracket st k top p hi hona chahiye 
            }else if(s[i] == '}'  ){
                if(st.empty()){
                    return false;
                }
                 if(st.top() == '{'){
                    st.pop();
            
                 }else{
                    return false;
                 }
            }else if(s[i] == ']'  ){
                if(st.empty()){
                    return false;
                }
                 if(st.top() == '['){
                    st.pop();
                    
                 }else{
                    return false;
                 }
            }else if(s[i] == ')'  ){
                if(st.empty()){//edge case when the no.of closing bracket are more than opening bracket before checking, then string is invalid due to insufficient opening brackets
                    return false;
                }//before accessing we shd check is st is empty 
                 if(st.top() == '('){
                    st.pop();
                    
                 }else{
                    return false;
                 }
            }
        }
        //kyuki har opening bracket k liye closing bracket exist krta hai to loop k baad stack empty ho jaani chahiye par agar aisa nhi h yani opening bracket no. m jyada the closing bracket se and it is invalid string
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }