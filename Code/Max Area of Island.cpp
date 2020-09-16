class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int r, int c)
    {
        return (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1);
    }
    void dfs(vector<vector<int>>& grid, int r, int c, int &count)
    {
        count++;
        grid[r][c] = 0;
        if(isSafe(grid, r - 1, c))
        {
            dfs(grid, r - 1, c, count);
        }
        if(isSafe(grid, r + 1, c))
        {
            dfs(grid, r + 1, c, count);
        }
        if(isSafe(grid, r, c - 1))
        {
            dfs(grid, r, c - 1, count);
        }
        if(isSafe(grid, r, c + 1))
        {
            dfs(grid, r, c + 1, count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int count = 0;
                    dfs(grid, i, j, count);
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};
