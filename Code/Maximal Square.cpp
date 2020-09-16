class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                if(dp[i][j] == 0 || i == 0 || j == 0){
                    ans = max(ans, dp[i][j]);
                    continue;
                }
                dp[i][j] += min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};
