class MedianFinder {
public:
    priority_queue<int,vector<int>> q1;
    priority_queue<int,vector<int>, greater<int> > q2;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(q1.empty())
        {
            q1.push(num);
            return;
        }
        if(q2.empty())
        {
            if(num >= q1.top())
                q2.push(num);
            else
            {
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
            return;
        }
        if(q1.size() > q2.size())
        {
            if(q1.top() >= num )
            {
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
            else
            {
                q2.push(num);
            }
        }
        else
        {
            if(num <= q2.top())
            {
                q1.push(num);
            }
            else
            {
                q1.push(q2.top());
                q2.pop();
                q2.push(num);
            }
        }
    }
    
    double findMedian() {
        if(q1.size() > q2.size())
            return q1.top();
        else
            return ((double)q1.top() + (double)q2.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
