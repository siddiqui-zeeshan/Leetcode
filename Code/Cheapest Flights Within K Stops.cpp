class Solution {
public:
    int dfs(vector<vector<pair<int,int>>>& A, vector<bool>& vis, vector<vector<int>>& dp, 
            int v, int dst, int k, int K)
    {
        if(k - 1 > K)
            return -1;
        if(v == dst)
            return 0;
        if(dp[v][k] != -2)
            return dp[v][k];
        int ans = INT_MAX;
        bool flag = false;
        vis[v] = true;
        for(int i = 0; i < A[v].size(); i++)
        {
            if(true)
            {
                int dist = dfs(A, vis, dp, A[v][i].first, dst, k + 1, K);
                if(dist != -1)
                {
                    flag = true;
                    dist += A[v][i].second;
                    ans = min(ans, dist);
                }
            }
        }
        vis[v] = false;
        if(!flag)
            return dp[v][k] = -1;
        return dp[v][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> A(n);
        for(int i = 0; i < flights.size(); i++)
        {
            A[flights[i][0]].push_back({flights[i][1], flights[i][2]});
            //A[flights[i][1]].push_back({flights[i][0], flights[i][2]});
        }
        vector<bool> vis(n, false);
        vector<vector<int>> dp(n + 5, vector<int> (K + 5, -2));
        int ans = dfs(A, vis, dp, src, dst, 0, K);
        return ans;
    }
};
