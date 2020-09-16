class Solution {
public:
    int leastInterval(vector<char>& A, int n) {
        if(A.empty())
            return 0;
        int f[26];
        memset(f, 0, sizeof(f));
        for(auto i : A)
        {
            f[i - 'A']++;
        }
        int count = 0;
        priority_queue<int> pq;
        for(auto i : f)
        {
            if(i != 0)
                pq.push(i);
        }
        
        while(!pq.empty())
        {
            int t = 0;
            vector<int> temp;
            for(int i = 0; i <= n; i++)
            {
                if(!pq.empty())
                {
                    int x = pq.top();
                    x--;
                    pq.pop();
                    if(x != 0)
                        temp.push_back(x);
                    t++;
                }
            }
            
            for (int cnt : temp) {
                    pq.push(cnt);
            }
            
            count += !pq.empty() ? n + 1 : t;
        }
        return count;
    }
};
