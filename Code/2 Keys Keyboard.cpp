class Solution {
public:
    int funct(int n, int l, int s, vector<vector<int>>& dp)
    {
        if(l > n)
            return INT_MAX;
        if(l == n)
            return 1;
        if(dp[l][s] != -1)
            return dp[l][s];
        int cpy = funct(n, l + l, l, dp);
        int add = funct(n, l + s, s, dp);
        if(cpy != INT_MAX)
            cpy += 2;
        if(add != INT_MAX)
            add += 1;
        return dp[l][s] = min(add, cpy);
            
    }
    int minSteps(int n) {
        if(n == 1)
            return 0;
        vector<vector<int>> dp(2 * n, vector<int> (2 * n, -1));
        return funct(n, 1, 1, dp);
    }
};
