class Solution {
public:
    int trap(vector<int>& h) {
        stack<int> s;
        int res = 0;
        for(int i = 0; i < h.size(); i++)
        {
            while(!s.empty() && h[i] > h[s.top()])
            {
                int top = s.top();
                s.pop();
                if(s.empty())
                    break;
                int dist = i - s.top() - 1;
                int hei = min(h[s.top()], h[i]) - h[top];
                res += dist * hei;
            }
            s.push(i);
        }
        return res;
    }
};
