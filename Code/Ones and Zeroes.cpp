class Solution {
public:
    int recur(vector<vector<int>>& A, int zero, int one, int pos, vector<vector<vector<int>>>& dp)
    {
        if(pos == A.size())
            return 0;
        if(dp[pos][zero][one] != -1)
            return dp[pos][zero][one];
        int s1 = 0;
        if(zero - A[pos][0] >= 0 && one - A[pos][1] >= 0){
            s1 = 1 + recur(A, zero - A[pos][0], one - A[pos][1], pos + 1, dp);
        }
        int s2 = recur(A, zero, one, pos + 1, dp);
        dp[pos][zero][one] = max(s1, s2);
        return max(s2, s1);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> A(strs.size(), vector<int> (2, 0));
        for(int i = 0; i < strs.size(); i++)
        {
            int one, zero;
            one = zero = 0;
            for(int j = 0; j < strs[i].size(); j++)
            {
                int x = strs[i][j] == '1' ? ++one : ++zero;
            }
            A[i][0] = zero;
            A[i][1] = one;
        }
        vector<vector<vector<int>>> dp(A.size() + 10, vector<vector<int>>(m + 10, vector<int>(n + 10, -1)));
        return recur(A, m, n, 0, dp);
    }
};
