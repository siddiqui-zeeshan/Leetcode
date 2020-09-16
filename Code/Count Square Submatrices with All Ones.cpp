class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        vector<vector<int>> dp = matrix;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(dp[i][j] == 0 || i == 0 || j == 0){
                    continue;
                }
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
