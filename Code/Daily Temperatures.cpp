class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        if(T.size() == 0)
            return vector<int>();
        s.push(T.size() - 1);
        vector<int> res(T.size(), 0);
        res[T.size() - 1] = 0;
        for(int i = T.size() - 2; i >= 0; i--)
        {
            if(T[i] < T[s.top()])
            {
                res[i] = s.top() - i;
                s.push(i);
            }
            else
            {
                while(!s.empty() && T[s.top()] <= T[i])
                {
                    s.pop();
                }
                if(s.empty())
                    res[i] = 0;
                else
                    res[i] = s.top() - i;
                s.push(i);
            }
        }
        return res;
    }
};
