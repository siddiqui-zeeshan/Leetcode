class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2)
            return 0;
        int dp[A.size()];
        memset(dp,0,sizeof(dp));
        int sum = 0;
        for(int i = 2; i < A.size(); i++)
        {
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                dp[i] = 1 + dp[i - 1];
                sum += dp[i];
            }
        }
        return sum;
    }
};
