class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        if(A.empty())
            return {};
        vector<int> dp(A.size(), 1), pos(A.size(), 0);
        sort(A.begin(), A.end());
        dp[0] = 1;
        int idx = 0;
        for(int i = 1; i < A.size(); i++)
        {
            pos[i] = i;
            for(int j = 0; j < i; j++)
            {
                if(A[i] % A[j] == 0)
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        pos[i] = j;
                    }
                    if(dp[i] > dp[idx])
                        idx = i;
                }
            }
        }
        for(auto d : dp)
        {
            cout<<d<<" ";
        }
        vector<int> res;
        //res.push_back(A[idx]);
        while(pos[idx] != idx)
        {
            res.push_back(A[idx]);
            idx = pos[idx];
        }
        res.push_back(A[idx]);
        reverse(res.begin(), res.end());
        return res;
    }
};
