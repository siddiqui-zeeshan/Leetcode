class Solution {
public:
    bool isSafe(vector<vector<vector<int>>> &vis, int m, int n, int N, int i, int j)
    {
        return i >= 0 && i <= m + 1 && j >= 0 && j <= n + 1;
    }
    int dfs(vector<vector<vector<int>>> &vis, int m, int n, int N, int i, int j)
    {
        if(i == 0 || j == 0 || i == m + 1 || j == n + 1)
        {
            return 1;
        }
        if(N == 0)
        {
            return 0;
        }
        if(vis[i][j][N] != -1)
            return vis[i][j][N];
        int sum = 0;
        if(isSafe(vis, m, n, N, i - 1, j))
            sum = (sum % 1000000007 + dfs(vis, m, n, N - 1, i - 1, j) % 1000000007) % 1000000007; 
        if(isSafe(vis, m, n, N, i, j - 1))
            sum = (sum % 1000000007 + dfs(vis, m, n, N - 1, i, j - 1) % 1000000007) % 1000000007; 
        if(isSafe(vis, m, n, N, i + 1, j))
            sum = (sum % 1000000007 + dfs(vis, m, n, N - 1, i + 1, j) % 1000000007) % 1000000007; 
        if(isSafe(vis, m, n, N, i, j + 1))
            sum = (sum % 1000000007 + dfs(vis, m, n, N - 1, i, j + 1) % 1000000007) % 1000000007;
        return vis[i][j][N] = sum;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> vis(m + 2, vector<vector<int>>(n + 2, vector<int>(N + 1, -1)));
        i += 1;
        j += 1;
        return dfs(vis, m, n, N, i, j);
    }
};
