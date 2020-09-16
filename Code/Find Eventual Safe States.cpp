class Solution {
public:
    bool dfs(int v, vector<vector<int>>& A, vector<bool>& vis, vector<int>& res)
    {
        if(A[v].size() == 0)
            return true;
        vis[v] = true;
        if(res[v] != -1)
            return res[v];
        int count = 0;
        for(int i = 0; i < A[v].size(); i++)
        {
            if(!vis[A[v][i]] && dfs(A[v][i], A, vis, res))
                count++;
            else if(vis[A[v][i]] && res[A[v][i]] == 1)
                count++;
        }
        if(count == A[v].size())
            res[v] = 1;
        else
            res[v] = 0;
        return res[v];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++)
        {
            vector<bool> vis(graph.size(), false);
            if(res[i] == -1)
                res[i] = dfs(i, graph, vis, res);
        }
        vector<int> ans;
        for(int i = 0; i < res.size(); i++)
        {
            //cout<<res[i]<<" ";
            if(res[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};
