class Solution {
public:
    bool isSafe(int x, int y, vector<vector<char>>& A)
    {
        return (x >= 0 && y >= 0 && x < A.size() && y < A[0].size() && A[x][y] == 'X');
    }
    void dfs(int x, int y, char poi, vector<vector<char>>& A)
    {
        A[x][y] = 'q';
        if(isSafe(x - 1, y, A))
        {
            dfs(x - 1, y, poi, A);
        }
        if(isSafe(x + 1, y, A))
        {
            dfs(x + 1, y, poi, A);
        }
        if(isSafe(x, y - 1, A))
        {
            dfs(x, y - 1, poi, A);
        }
        if(isSafe(x, y + 1, A))
        {
            dfs(x, y + 1, poi, A);
        }
    }
    int countBattleships(vector<vector<char>>& A) {
        int res = 0;
        int poi = 0;
        poi++;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[0].size(); j++)
            {
                
                if(A[i][j] == 'X')
                {
                    //cout<<i<<" "<<j<<endl;
                    poi++;
                    dfs(i, j, poi, A);
                    
                }
            }
        }
        
        // for(int i = 0; i < A.size(); i++)
        // {
        //     for(int j = 0; j < A[0].size(); j++)
        //     {
        //         if(A[i][j] == 'X' && A[i][j] == '.')
        //             cout<<A[i][j]<<" ";
        //         if(A[i][j] != 'X' && A[i][j] != '.')
        //         {
        //             int z = 'Z';
        //             z++;
        //             int n = A[i][j] - z;
        //             cout<<n<<" ";
        //             res = max(res, n);
        //         }
        //     }
        //     cout<<endl;
        // }
        return --poi;
    }
};
