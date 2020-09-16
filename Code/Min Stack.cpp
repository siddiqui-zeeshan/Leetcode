class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, minS;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if((!minS.empty() && minS.top() > x) || minS.empty())
            minS.push(x);
        else if(!minS.empty() && minS.top() <= x)
            minS.push(minS.top());
        
        
    }
    
    void pop() {
        minS.pop();
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
