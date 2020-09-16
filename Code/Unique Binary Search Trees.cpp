class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        dp.push_back(1);
        for(int i = 1; i <= n; i++)
        {
            int t = 0;
            for(int j = 0; j < i; j++)
            {
                t += dp[j] * dp[i - j - 1];
            }
            dp.push_back(t);
        }
        return dp.back();
    }
};
