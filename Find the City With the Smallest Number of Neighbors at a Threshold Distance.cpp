class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        int INF = 1e6;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for(int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        for(auto i : edges)
        {
            int v1 = i[0];
            int v2 = i[1];
            int di = i[2];
            dist[v1][v2] = dist[v2][v1] = di;
        }
        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int minD = n;
        int ver;
        for(int i = 0; i < n ; i++)
        {
            int r = 0;
            for(int j = 0; j < n; j++)
            {
                if(dist[i][j] <= th)
                    r++;
            }
            if(r <= minD)
            {
                ver = i;
                minD = r;
            }
        }
        return ver;
    }
};
