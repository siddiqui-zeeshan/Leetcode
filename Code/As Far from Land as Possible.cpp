class Solution {
public:
    int maxDistance(vector<vector<int>>& A) {
        if(A.size() == 0)
            return -1;
        bool flag = false;
        vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), INT_MAX - 100000));
        
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[0].size(); j++)
            {
                if(A[i][j] == 1)
                {
                    dp[i][j] = 0;
                    flag = true;
                }
                else
                {
                    if (i > 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
            
        }
        if(flag==false)
            return -1;
        for(int i = A.size() - 1; i >= 0; i--)
        {
            for(int j = A[0].size() - 1; j >= 0 ; j--)
            {
                
                //cout<<dp[i][j]<<" ";
                    if (i < A.size() - 1)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    if (j < A[0].size() - 1)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                
            }
            //cout<<endl;
            
        }
        
        int d = -1;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0 ; j < A[0].size(); j++)
            {
                if(A[i][j] == 0)
                    d = max(d, dp[i][j]);
            }
        }
        return d;
    }
};
