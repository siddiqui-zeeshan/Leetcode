class Solution {
public:
    bool isSafe(vector<vector<char>> &A, int x, int y, int X, int Y)
    {
        return (x>=0 && y>=0 && x<X && y<Y && A[x][y]=='O');
    }
    void dfs(vector<vector<char>> &A, int x, int y)
    {
        A[x][y]='*';
        static int X[4]={-1, 0, 1, 0};
        static int Y[4]={0, -1, 0, 1};
        for(int i=0;i<4;i++)
        {
            if(isSafe(A, x+X[i], y+Y[i], A.size(), A[0].size()))
            {
                dfs(A, x+X[i], y+Y[i]);
            }
        }
    }
    void solve(vector<vector<char>>& A) {
        if(A.empty())
            return;
        for(int i=0;i<A[0].size();i++)
        {
            if(A[0][i]=='O')
                dfs(A, 0, i);
        }
        for(int i=0;i<A.size();i++)
        {
            if(A[i][0]=='O')
            {
                dfs(A, i, 0);
            }
        }
        for(int i=0;i<A.size();i++)
        {
            if(A[i][A[0].size()-1]=='O')
            {
                dfs(A, i, A[0].size()-1);
            }
        }
        for(int i=0;i<A[0].size();i++)
        {
            if(A[A.size()-1][i]=='O')
            {
                dfs(A, A.size()-1, i);
            }
        }
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
            {
                if(A[i][j]=='O')
                    A[i][j]='X';
            }
        }
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
            {
                if(A[i][j]=='*')
                    A[i][j]='O';
            }
        }
    }
};
