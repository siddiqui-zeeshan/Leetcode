class Solution {
public:
    int recur(vector<int>& A, int s, int f, int fuel, vector<vector<int>>& dp)
    {
        if(fuel == 0)
        {
            if(s == f)
                return 1;
            if(s != f)
                return 0;
        }
        if(dp[s][fuel] != -1)
            return dp[s][fuel];
        int res = 0;
        if(s == f)
            res = (res % 1000000007 + 1) % 1000000007;
        for(int i = 0; i < A.size(); i++)
        {
            if(s == i)
                continue;
            int dif = abs(A[i] - A[s]);
            if(fuel - dif >= 0)
            {
                res = (res % 1000000007 + recur(A, i, f, fuel - dif, dp) % 1000000007) % 1000000007;
            }
        }
        dp[s][fuel] = res;
        return res;
    }
    int countRoutes(vector<int>& A, int start, int finish, int fuel) {
        vector<vector<int>> dp(A.size() + 5, vector<int>(fuel + 5, -1));
        return recur(A, start, finish, fuel, dp);
    }
};
