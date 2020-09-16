class Solution {
public:
    
    
    bool isSafe(int x, int y, vector<vector<int>>& A, vector<vector<bool>> &ocean)
    {
        return (x >= 0 && x < A.size() && y >= 0 && y < A[0].size() 
                && ocean[x][y] == false);
    }
    
    void dfs(int x, int y, vector<vector<int>>& A, vector<vector<bool>> &ocean)
    {
        ocean[x][y] = true;
        
        if(isSafe(x - 1, y, A, ocean) && A[x][y] <= A[x - 1][y])
        {
            dfs(x - 1, y, A, ocean);
        }
        if(isSafe(x, y - 1, A, ocean) && A[x][y] <= A[x][y - 1])
        {
            dfs(x, y - 1, A, ocean);
        }
        if(isSafe(x + 1, y, A, ocean) && A[x][y] <= A[x + 1][y])
        {
            dfs(x + 1, y, A, ocean);
        }
        if(isSafe(x, y + 1, A, ocean) && A[x][y] <= A[x][y + 1])
        {
            dfs(x, y + 1, A, ocean);
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) {
        vector<vector<int>> res;
        if(A.empty())
            return res;
        vector<vector<bool>> atl, pac;
        vector<vector<bool>> temp(A.size(), vector<bool>(A[0].size(), false));
        atl = pac = temp;
        
        for(int i = 0; i < A.size(); i++)
        {
            dfs(i, 0, A, pac);
            dfs(i, A[0].size() - 1, A, atl);
        }
        for(int i = 0; i < A[0].size(); i++)
        {
            dfs(0, i, A, pac);
            dfs(A.size() - 1, i, A, atl);
        }
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[0].size(); j++)
            {
                if(atl[i][j] && pac[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
