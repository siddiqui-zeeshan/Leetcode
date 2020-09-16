class Solution {
public:
    void dfs(int N, int K, string s, vector<int>& res)
    {
        //cout<<s<<endl;
        if(s.length() == N)
        {
            res.push_back(stoi(s));
            return;
        }
        for(int i = 0; i <= 9; i++)
        {
            if(s.size() == 0 && i != 0)
            {
                char a = i + '0';
                s = s + a;
                dfs(N, K, s, res);
                s.pop_back();
            }
            else if(s.size() != 0)
            {
                if(abs(s[s.length() - 1] - (i + '0')) == K)
                {
                    char a = i + '0';
                    s = s + a;
                    dfs(N, K, s, res);
                    s.pop_back();
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        if(N == 1)
            res.push_back(0);
        dfs(N, K, "", res);
        return res;
    }
};
