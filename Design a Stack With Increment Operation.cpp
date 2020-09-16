class CustomStack {
public:
    vector<int> rec;
    stack<int> s;
    int pos;
    int n;
    CustomStack(int maxSize) {
        rec.resize(maxSize);
        n = maxSize;
        for(int i = 0; i < n; i++)
            rec[i] = 0;
        pos = -1;
    }
    
    void push(int x) {
        if(pos == n - 1)
            return;
        s.push(x);
        pos++;
    }
    
    int pop() {
        if(pos == -1)
            return -1;
        int x = s.top() + rec[pos];
        s.pop();
        rec[pos] = 0;
        pos--;
        return x;
        
    }
    
    void increment(int k, int val) {
        int x = min(pos + 1, k);
        for(int i = 0; i < x; i++)
        {
            rec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
