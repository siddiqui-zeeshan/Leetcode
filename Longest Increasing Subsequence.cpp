class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        if(n==0)
            return 0;
        vector<int> dp(n, 1);
        int m = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(A[j] < A[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    m = max(dp[i], m);
                }
            }
        }
        for(int i = 0; i < n; i++)
            cout<<dp[i]<<" ";
        return m;
    }
};
