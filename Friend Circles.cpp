class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<bool>& vis, int v)
    {
        vis[v] = true;
        
        for(int i = 0; i < M[0].size(); i++)
        {
            if(M[v][i] == 1 && !vis[i])
            {
                dfs(M, vis, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty())
            return 0;
        vector<bool> vis(M.size(), false);
        int count = 0;
        
        for(int i = 0; i < M.size(); i++)
        {
            for(int j = 0; j < M[0].size(); j++)
            {
                if(M[i][j] == 1 && !vis[j])
                {
                    //cout<<j<<" ";
                    count++;
                    dfs(M, vis, j);
                }
            }
        }
        return count;
    }
};
