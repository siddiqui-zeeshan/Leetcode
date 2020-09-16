class Solution {
public:
    int funct(int n, vector<int>& dp)
    {
        if(n == 0)
            return 0;
        if(n < 0)
            return -1;
        int ans = INT_MAX;
        if(dp[n] != -2)
            return dp[n];
        for(int i = 1; i <= sqrt(n); i++)
        {
            int step = funct(n - i * i, dp);
            if(step != -1)
                ans = min(ans, step + 1);
        }
        return dp[n] = ans == INT_MAX ? -1 : ans;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -2);
        return funct(n, dp);
    }
};
