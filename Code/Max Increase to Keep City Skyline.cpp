class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> hor(grid[0].size(), 0);
        vector<int> ver(grid.size(), 0);
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                ver[i] = max(ver[i], grid[i][j]);
            }
        }
        for(int j = 0; j < grid[0].size(); j++)
        {
            for(int i = 0; i < grid.size(); i++)
            {
                hor[j] = max(hor[j], grid[i][j]);
            }
        }
        int sum = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                sum += abs(grid[i][j] - min(hor[j], ver[i]));
            }
        }
        return sum;
    }
};
