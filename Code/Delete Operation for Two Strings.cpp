class Solution {
public:
    int minDistance(string w1, string w2) 
    {
        vector<vector<int>> dp(w1.length() + 1, vector<int> (w2.length() + 1, 0));
        for(int i = 1; i <= w1.length(); i++)
        {
            for(int j = 1; j <= w2.length(); j++)
            {
                if(w1[i - 1] == w2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return w1.length() + w2.length() - 2 * dp[w1.length()][w2.length()];
    }
};
