class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;
        while( i<n){
            string word = "";//next word shuru hua 
            while(s[i] == ' ')i++;//jab string m space hai to hmne space ko skip kiya or aage badh gye
            while(i<n && s[i] != ' '){//build a word 
                word+= s[i];//jab space nhi cont char hi to vo saare cont char ko ek sath ek word bnake aage badh gye 
                i++;
            }
            // Push non-empty word
        if (!word.empty()) st.push(word);//us word ko stack m push kiya 


        }
       //by the end of this loop saare word stack m push ho gye
       string result = "";
       while(!st.empty()){
        result += st.top();
        st.pop();
        //agar vo word last word nhi hai to us word k baad ' ' daalna hoga 
        if(!st.empty()) result += " ";

       }
        
    return result; 
    }
};