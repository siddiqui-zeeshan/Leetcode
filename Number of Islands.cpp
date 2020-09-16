class Solution {
public:
    vector<vector<char>> g;
    
    bool isSafe(int x, int y, vector<vector<bool>> &vis)
    {
        //cout<<x<<" "<<y<<endl;
        if (x>=0 && y>=0 && x<g.size() && y<g[0].size() && vis[x][y]==false && g[x][y]=='1')
        {
           // cout<<"hg "<<x<<" "<<y<<endl;
            return true;
        }
        else
            return false;
    }
    void dfs(int x, int y, vector<vector<bool>> &vis)
    {
        vis[x][y] = true;
        if(isSafe(x-1, y, vis))
            dfs(x-1, y, vis);
        if(isSafe(x, y-1, vis))
            dfs(x, y-1, vis);
        if(isSafe(x+1, y, vis))
            dfs(x+1, y, vis);
        if(isSafe(x, y+1, vis))
            dfs(x, y+1, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int count = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        
        g=grid;
        
        for(int i = 0; i < g.size(); i++)
        {
            for(int j = 0; j < g[0].size(); j++)
            {
                if(g[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    dfs(i, j, vis);
                }
            }
        }
        return count;
    }
};
