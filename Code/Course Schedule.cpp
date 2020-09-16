class Solution {
public:
    //vector<int> adj[100001];
    bool dfs(int v, vector<bool> &vis, vector<bool> &rec, vector<int> adj[])
    {
        if(!vis[v])
        {
            vis[v] = true;
            rec[v] = true;
            for(auto i = adj[v].begin(); i != adj[v].end(); i++)
            {
                if(!vis[*i] && dfs(*i, vis, rec, adj))
                    return true;
                else if(rec[*i])
                    return true;
            }
        }
        rec[v] = false;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& A) {
        vector<int> adj[num];
        for(int i = 0; i < A.size(); i++)
        {
            adj[A[i][0]].push_back(A[i][1]);
        }
        vector<bool> vis(num, false);
        vector<bool> rec(num, false);
        
        for(auto i = 0; i < num; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, vis, rec, adj))
                    return false;
            }
        }
        return true;
    }
};
