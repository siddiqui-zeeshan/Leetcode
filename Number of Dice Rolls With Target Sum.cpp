class Solution {
public:
    int func(int d, int f, int target, vector<vector<int>>& dp)
    {
        if (d == 0 || target <= 0) return d == target;
        int res = 0;
        if(dp[d][target] != -1)
            return dp[d][target];
        for(int i = 1; i <= f; i++)
        {
            res = (res % 1000000007  + func(d - 1, f, target - i, dp) % 1000000007) % 1000000007;
        }
        return  dp[d][target] = res;       
    }
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 5, vector<int> (target + 5, -1));
        return func(d, f, target, dp);
    }
};
