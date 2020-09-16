class Solution {
public:
    int coinChange(vector<int>& A, int n) {
        if(n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] <= n)
                dp[A[i]] = 1;
        }
        for(int i = 2; i <= n; i++)
        {
            if(dp[i] == 1)
                continue;
            int amt = INT_MAX - 100;
            bool flag = false;
            for(int j = 0; j < A.size(); j++)
            {
                if(i - A[j] <= 0)
                    continue;
                else if(dp[i - A[j]] == 0)
                    continue;
                else
                {
                    amt = min(amt, dp[i - A[j]] + 1);
                    flag = true;
                }
            }
            if(flag)
                dp[i] = amt;
        }
        return dp[n] == 0? -1 : dp[n];
    }
};
