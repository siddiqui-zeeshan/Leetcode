class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> index;
        int ans = 0;
        for(int i = 0; i < A.size(); i++)
        {
            index[A[i]] = i;
        }
        vector<vector<int>> dp(A.size() + 10, vector<int> (A.size() + 10, 0));
        for(int i = 1; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                int d = A[i] - A[j];
                if(d >= A[j]){
                    dp[i][index[A[j]]] = 2;
                    continue;
                }
                if(index.find(d) != index.end())
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[j][index[d]]);
                }
                else
                {
                    dp[i][j] = 2;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans > 2 ? ans : 0;
    }
};
