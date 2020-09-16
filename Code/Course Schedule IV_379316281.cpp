class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int p, int q, vector<vector<int>>& dp)
    {
        if(dp[p][q] != -1)
            return dp[p][q];
        for(int i = 0; i < adj[p].size(); i++)
        {
            if(adj[p][i] == q || dfs(adj, adj[p][i], q, dp)){
                dp[p][q] = 1;
                return true;
            }
        }
        dp[p][q] = 0;
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pr, vector<vector<int>>& qr) 
    {
        vector<vector<int>> adj(n);
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        for(int i = 0 ; i < pr.size(); i++)
        {
            int a = pr[i][0];
            int b = pr[i][1];
            adj[b].push_back(a);
            dp[b][a] = 1;
        }
        vector<bool> res(qr.size(), false);
        for(int i = 0; i < qr.size(); i++)
        {
            int p = qr[i][1];
            int q = qr[i][0];
            if(dfs(adj, p, q, dp))
                res[i] = true;
        }
        return res;
    }
};
