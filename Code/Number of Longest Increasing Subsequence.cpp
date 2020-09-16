class Solution {
public:
    int findNumberOfLIS(vector<int>& A) {
        if(A.size() <= 1)
            return A.size();
        int n = A.size();
        vector<int> rec(A.size(), 1);
        rec[1] = 1;
        if(n==0)
            return 0;
        vector<int> dp(n, 1);
        int m = 0;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            dp[i] = rec[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(A[j] < A[i])
                {
                    
                    if(dp[i] == dp[j] + 1)
                        rec[i] += rec[j]; 
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        rec[i] = rec[j];
                    }
                }
            }
            if(m == dp[i])
            {
                res += rec[i];
            }
            if(m < dp[i])
            {
                res = rec[i];
                m = dp[i];
            }
        }
        return res;
    }
};
