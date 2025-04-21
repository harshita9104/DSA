class Solution {
public:
    string reverseWords(string s) {
        //the reverse of a string with no elem is same
        if(s.size() == 0) return s;
        //stack should be used as in stack if we push the elem then the last elem added will be at the top of stack
        // this staack will store strings 
        stack<string> st;
        //and a string which will store the reversed string
        string result;
        //we will push the string we get in stack when we will get space or null char 
        for(int i = 0; i<s.size(); i++){
            string word;//before a new word starts to build after a space the word will again be intialised as a empty string 
            if(s[i] == ' ')continue;
            while(i<s.size() && s[i] != ' '){
                word += s[i];
                i++;
            }
            // after we have got a word from string s push it in stack
            st.push(word);         
        }//after this for loop the stack will have all the words in string s 
        //now to put these words from stack to result string
        while(!st.empty()){
            result += st.top();//add the top word on stack in our result string
            st.pop();//pop that word now 
            if(!st.empty()) result+= ' ';//add a space after that word is added in result string make sure that was not the last word of stack as there is no need to add space after the last word is added in result string
        }
        return result;

    }
};