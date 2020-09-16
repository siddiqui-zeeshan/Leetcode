class Solution {
public:
    int funct(int n, vector<int>& A, int prev, int count, vector<vector<vector<int>>>& dp)
    {
        if(n == 0)
            return 1;
        int ans = 0;
        if(prev >= 0 && dp[n][prev][count] != -1)
            return dp[n][prev][count];
        for(int i = 0; i < 6; i++)
        {
            if(i == prev && count + 1 > A[i])
                continue;
            if(i == prev && count + 1 <= A[i])
                ans = (ans % 1000000007 + funct(n - 1, A, prev, count + 1, dp) % 1000000007) % 1000000007;
            else
                ans = (ans % 1000000007 + funct(n - 1, A, i, 1, dp) % 1000000007) % 1000000007;
        }
        if(prev >= 0)
            dp[n][prev][count] = ans;
        return ans;
    }
    int dieSimulator(int n, vector<int>& A) {
        vector<vector<vector<int>>> dp(n + 5, vector<vector<int>>(7, vector<int>(16, -1)));
        return funct(n, A, -1, 0, dp);
    }
};
