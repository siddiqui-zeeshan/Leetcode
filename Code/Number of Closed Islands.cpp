class Solution {
public:
    bool isSafeFill(vector<vector<int>>& grid, int r, int c)
    {
        return (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 0);
    }
    void dfs1(vector<vector<int>>& grid, int r, int c)
    {
        grid[r][c] = 1;
        if(isSafeFill(grid, r - 1, c))
        {
            dfs1(grid, r - 1, c);
        }
        if(isSafeFill(grid, r + 1, c))
        {
            dfs1(grid, r + 1, c);
        }
        if(isSafeFill(grid, r, c - 1))
        {
            dfs1(grid, r, c - 1);
        }
        if(isSafeFill(grid, r, c + 1))
        {
            dfs1(grid, r, c + 1);
        }
    }
    bool isSafe(vector<vector<int>>& grid, int r, int c)
    {
        return (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 0);
    }
    void dfs(vector<vector<int>>& grid, int r, int c)
    {
        grid[r][c] = 1;
        if(isSafe(grid, r - 1, c))
        {
            dfs(grid, r - 1, c);
        }
        if(isSafe(grid, r + 1, c))
        {
            dfs(grid, r + 1, c);
        }
        if(isSafe(grid, r, c - 1))
        {
            dfs(grid, r, c - 1);
        }
        if(isSafe(grid, r, c + 1))
        {
            dfs(grid, r, c + 1);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
        {
            if(grid[i][0] == 0)
                dfs1(grid, i, 0);
            if(grid[i][grid[0].size() - 1] == 0)
                dfs1(grid, i, grid[0].size() - 1);
        }
        for(int i = 0; i < grid[0].size(); i++)
        {
            if(grid[0][i] == 0)
                dfs1(grid, 0, i);
            if(grid[grid.size() - 1][i] == 0)
                dfs1(grid, grid.size() - 1, i);
        }
        int res = 0;
        // for(int i = 0; i < grid.size(); i++)
        // {
        //     for(int j = 0; j < grid[0].size(); j++)
        //     {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0)
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
