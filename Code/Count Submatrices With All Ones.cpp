class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        auto dp = mat;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n;i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(j == 0)
                    continue;
                if(mat[i][j] == 0)
                    continue;
                dp[i][j] += dp[i][j - 1];
            }
        }
        int ans = 0;
        for(int j = 0; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                int minim = dp[i][j];
                for(int k = i; k >= 0; k--)
                {
                    minim = min(minim, dp[k][j]);
                    if(minim == 0)
                        break;
                    ans += minim;
                }
            }
        }
        return ans;
    }
};
