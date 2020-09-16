class Solution {
public:
    int maxProfit(vector<int>& A) {
        int n = A.size();
        if(n == 0 || n == 1)
            return 0;
        int dp[n];
        dp[0] = A[0];
        
        for(int i = 1; i < n; i++)
        {
            if(A[i] < dp[i-1])
            {
                dp[i] = A[i];
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        int prof = 0;
        for(int i = 0; i < n; i++)
        {
            prof = max(prof, A[i] - dp[i]);
        }
        return prof;
    }
};
