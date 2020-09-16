class Solution {
public:
    vector<vector<int>> step = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool isSafe(vector<vector<char>>& grid, int r, int c)
    {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
    
    bool isCycle(vector<vector<char>>& grid, int r, int c, int parr, int parc, vector<vector<bool>>& vis, int steps)
    {
        vis[r][c] = true;
        //cout<<r<<" "<<c<<endl;
        for(int i = 0; i < 4; i++)
        {
            int R = r + step[i][0];
            int C = c + step[i][1];
            
            if(isSafe(grid, R, C) && grid[R][C] == grid[r][c])
            {
                //cout<<grid[r][c]<<" "<<grid[R][C]<<endl;
                if(!vis[R][C])
                {
                    //cout<<"b "<<steps<<endl;
                    if(isCycle(grid, R, C, r, c, vis, steps + 1))
                    {
                        //cout<<"a "<<R<<" "<<C<<endl;
                        return true;
                    }
                }
                else if(R!= parr && C != parc)
                {
                    //cout<<"b "<<steps<< " "<<r<<" " <<c<<" "<<R<<" "<<C<<endl;
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int r, c;
        r = grid.size();
        c = grid[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                //vector<vector<bool>> vis(r, vector<bool>(c, false));
                if(!vis[i][j])
                {
                    if(isCycle(grid, i, j, -1, -1, vis, 0))
                    {
                        
                        return true;
                    }
                        
                }
                // for(int i = 0; i < r; i++)
                //         {
                //             for(int j = 0; j < c; j++)
                //             {
                //                 cout<<vis[i][j]<<" ";
                //             }
                //             cout<<endl;
                //         }
            }
        }
        return false;
    }
};
