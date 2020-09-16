class MyCircularQueue {
public:
    vector<int> q;
    int s, e, k;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        vector<int> temp(k, -1);
        s = e = 0;
        q = temp;
        this->k = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(s != e || (s == e && q[s] == -1)){
            q[e] = value;
            e = (e + 1) % k;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty())
        {
            q[s] = -1;
            s = (s + 1) % k;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return q[s];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        // for(auto i : q)
        //     cout<<i<<" ";
        // cout<<endl;
        int t = (e - 1);
        if(t < 0)
            t = k - 1;
        //cout<<t<<" ";
        return q[t];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(s == e && q[e] == -1)
            return true;
        else
            return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(s == e && q[e] != -1)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
