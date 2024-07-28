void pushAtBottom(stack<int> &Stk, int val){
  ////jo val abhi mili hai pushat bottom ko bas usko hi stack k empty hone p  bottom m daalke baaki saare elem ko aese hi push karna hai normally 

        if(Stk.empty()){
            Stk.push(val);
            return;
        }
        int tmp = Stk.top();
        Stk.pop();
        pushAtBottom(Stk, val);
        Stk.push(tmp);
    };
    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        int temp = St.top();
        St.pop();
        Reverse(St);//recursive call to reverse function with smaller stack
        //while backtracking of elem we cant push temp elem with normal push function
        //normally pushing temp one by one will give us same stack
        //so in order to reverse our stack, we need to push the temp elem at bottom one by one
        pushAtBottom(St, temp);
        
    }