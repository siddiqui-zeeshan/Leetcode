class Solution {
public:
    int minPathSum(vector<vector<int>>& A) {
        int n, m;
        n=A.size();
        m=A[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0]=A[0][0];
        
        for(int i=1;i<A[0].size();i++)
        {
            dp[0][i]+=A[0][i]+dp[0][i-1];
        }
        for(int i=1;i<A.size();i++)
        {
            dp[i][0]=dp[i-1][0]+A[i][0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=A[i][j]+min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
