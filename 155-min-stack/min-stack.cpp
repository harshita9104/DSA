class MinStack {
public:
    MinStack() {
        
    }
    //stack m pair daaldo push krte time jo val push ho rhi, abhi tk ki min value
    stack<pair<int,int>> s;
    void push(int val) {
        if(s.empty()){s.push({val,val});
        }else{
            int minval = min(val,s.top().second);
            s.push({val,minval});

        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */