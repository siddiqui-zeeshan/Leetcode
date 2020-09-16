class Solution {
public:
    int change(int amt, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 10, vector<int> (amt + 10, 0));
        
        for(int i = 0; i < dp.size(); i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= coins.size(); i++)
        {
            for(int j = 1; j <= amt; j++)
            {
                
                if(coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[coins.size()][amt];
    }
};
