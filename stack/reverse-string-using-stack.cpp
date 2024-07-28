// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.


void reverseString(vector<char>& s) {
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            st.push(s[i]);
        }
        for(int i = 0; i<s.size(); i++){
            char temp = st.top();
            s[i] = temp;
            st.pop();
        }

    }