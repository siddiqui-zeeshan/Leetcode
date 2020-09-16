class Solution {
public:
    int recur(vector<int>& cost, int pos, vector<int>& dp)
    {
        if(pos >= cost.size())
            return 0;
        if(dp[pos] != -1)
            return dp[pos];
        int c = cost[pos] + min(recur(cost, pos + 1, dp), recur(cost, pos + 2, dp));
        return dp[pos] = c;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.insert(cost.begin(), 0);
        vector<int> dp(cost.size() + 5, -1);
        return recur(cost, 0, dp);
    }
};
