class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
        string res = "";
        bool flag = true;
        
        while(!pq.empty())
        {
            
            auto i = pq.top();
            pq.pop();
            if(pq.empty()){
                res += pq.top().second;
                if(i.first >= 2)
                    res += pq.top().second;
                break;
            }
            else if(res.size() > 0 && res[res.size() - 1] == i.second)
            {
                auto t = pq.top();
                int a = t.first;
                int b = t.second;
                pq.pop();
                a--;
                res += b;
                if(a > 0)
                    pq.push({a, b});
                pq.push(i);
            }
            else 
            {
                int a = i.first;
                int b = i.second;
                if(a >= pq.top().first + 2)
                {
                    a -= 2;
                    res += b;
                    res += b;
                    if(a > 0)
                    {
                        pq.push({a, b});
                    }
                }
                else
                {
                    a -= 1;
                    res += b;
                    if(a > 0)
                    {
                        pq.push({a, b});
                    }
                }
            }
        }
        return res;
    }
};
