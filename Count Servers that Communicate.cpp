class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i = 0; i < r; i++)
        {
            int count = 0;
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                    count++;
            }
            if(count > 1)
            {
               for(int j = 0; j < c; j++)
                {
                    if(grid[i][j] == 1)
                        grid[i][j] = 2;
                } 
            }
        }
        
        for(int j = 0; j < c; j++)
        {
            int count = 0;
            for(int i = 0; i < r; i++)
            {
                if(grid[i][j] == 1 || grid[i][j] == 2)
                    count++;
            }
            if(count > 1)
            {
                for(int i = 0; i < r; i++)
                {
                    if(grid[i][j] == 1)
                        grid[i][j] = 2;
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 2)
                    count++;
            }
        }
        return count;
    }
};
