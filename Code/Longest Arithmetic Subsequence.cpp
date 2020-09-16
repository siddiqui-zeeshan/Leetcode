class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int, int>> dp(A.size());
        int ans = 0;
        for(int i = 1; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                int d = A[i] - A[j];
                if(dp[j].find(d) != dp[j].end())
                {
                    if(dp[i].find(d) != dp[i].end())
                    {
                        dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                    }
                    else
                    {
                        dp[i][d] = dp[j][d] + 1;
                    }
                }
                else
                {
                    if(dp[i].find(d) == dp[i].end())
                    {
                        dp[i][d] = 2;
                    }
                }
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};
