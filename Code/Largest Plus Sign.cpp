class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> dp(N, vector<int>(N, 1));
        for(auto i : mines)
        {
            dp[i[0]][i[1]] = 0;
        }
        vector<vector<int>> dp2 = dp;
        vector<vector<int>> dp3 = dp;
        vector<vector<int>> dp4 = dp;
        for(int i = 0; i < dp.size(); i++)
        {
            for(int j = 1; j < dp[0].size(); j++)
            {
                dp[i][j] = dp[i][j] == 0 ? 0 : dp[i][j] + dp[i][j - 1];
            }
        }
        
        for(int j = 0; j < dp[0].size(); j++)
        {
            for(int i = 1; i < dp.size(); i++)
            {
                dp3[i][j] = dp3[i][j] == 0 ? 0 : dp3[i][j] + dp3[i - 1][j];
            }
        }
        for(int i = dp.size() - 1; i >= 0; i--)
        {
            for(int j = dp.size() - 2; j >= 0; j--)
            {
                dp2[i][j] = dp2[i][j] == 0 ? 0 : dp2[i][j] + dp2[i][j + 1];
            }
        }
        
        for(int j = dp[0].size() - 1; j >= 0; j--)
        {
            for(int i = dp.size() - 2; i >= 0; i--)
            {
                dp4[i][j] = dp4[i][j] == 0 ? 0 : dp4[i][j] + dp4[i + 1][j];
            }
        }
        int order = 0;
        for(int i = 0; i < dp.size(); i++)
        {
            for(int j = 0; j < dp[0].size(); j++)
            {
                int o = min(dp[i][j], min(dp2[i][j], min(dp3[i][j], dp4[i][j])));
                order = max(o, order);
            }
        }
        return order;
    }
};
