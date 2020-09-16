class Solution {
public:
    bool isSafe(int r, int c, int R, int C)
    {
        return r >= 0 && c>= 0 && r < R && c < C;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int R = M.size();
        int C = M[0].size();
        vector<vector<int>> res(R, vector<int> (C, 0));
        vector<vector<int>> c = {{-1,0},{-1,-1},{0,-1},{1,0},{1,1},{0,1},{-1,1},{1,-1}};
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                int sum = M[i][j];
                int count = 1;
                for(int k = 0; k < 8; k++)
                {
                    if(isSafe(i + c[k][0], j + c[k][1], R, C))
                    {
                        count++;
                        sum += M[i + c[k][0]][j + c[k][1]];
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};
