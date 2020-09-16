class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        auto d1 = grid;
        auto d2 = grid;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(d1[i][j] == 0)
                    continue;
                d1[i][j] = j == 0 ? 1 : d1[i][j - 1] + 1;
                d2[i][j] = i == 0 ? 1 : d2[i - 1][j] + 1;
            }
        }
        int ans = 0;
        for(int i = grid.size() - 1; i >= 0 ; i--)
        {
            for(int j = grid[0].size() - 1; j >= 0 ; j--)
            {
                int small = min(d1[i][j], d2[i][j]);
                while(small > ans)
                {
                    if(d1[i - small + 1][j] >= small && d2[i][j - small + 1] >= small)
                        ans = small;
                    small--;
                }
            }
        }
        return ans * ans;
    }
};
