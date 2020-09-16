class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> ans;
        int n = mat.size();
        if(n == 0)
            return ans;
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = mat[0][0];
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] + mat[i][j];
                else if(j == 0)
                    dp[i][j] = dp[i - 1][j] + mat[i][j];
                else
                    dp[i][j] =  dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i][j];
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int s = (i - k >= 0 ? i - k : 0), e = (j - k >= 0 ? j - k : 0);
                int s1 = (i + k < n ? i + k : n - 1), e1 = (j + k < m ? j + k : m - 1);
                
                int sum = dp[s1][e1];
                if(s >= 1 && e >= 1)
                    sum += dp[s - 1][e - 1];
                if(s >= 1)
                    sum -= dp[s-1][e1];
                if(e >= 1)
                    sum -= dp[s1][e - 1];
                mat[i][j] = sum;
            }
        }
        
        return mat;
    }
};
