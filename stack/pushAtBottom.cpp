// You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack. 


//stack ko pass by ref karo taaki jo changes is function m ho vo actual st m bhi reflect ho jae
    void pushatbottom(stack<int> &st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        //store karlo jis elem ko pop krne wale ho kyuki usse backtracking m phirse push krna hoga
        int temp = st.top();
        st.pop();
        // call the fun recursively for smaller stack
        pushatbottom(st, x);
        //to push temp while backtracking
        st.push(temp);
    }
    stack<int> insertAtBottom(stack<int> st,int x){
        //its easy to push an elem at bottom of stack when the stack is empty
        //so we will recursively call stack for one elem less each time and when the stack becomes empty(base case) we will push the elem at bottom
        //and when we return from base case we will push the elem we popped one by one maintaining the order
        pushatbottom(st, x);
        return st;
        
    }