class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int k) {
        vector<pair<int, int>> adj[N + 1];
        for(int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
            //adj[times[i][1]].push_back({times[i][0], times[i][2]});
        }
        vector<int> dist(N + 1, 1000000);
        bool vis[N + 1];
        memset(vis, false, sizeof(vis));
        dist[k] = 0;
        multiset<pair<int, int>> s;
        s.insert({0, k});
        while(!s.empty())
        {
            pair<int, int> p = *s.begin();
            s.erase(s.begin());
            int x = p.second;
            int wei = p.first;
            if(vis[x])
                continue;
            vis[x] = true;
            for(int i = 0; i < adj[x].size(); i++)
            {
                int e = adj[x][i].first;
                int w = adj[x][i].second;
                if(dist[x] + w < dist[e]){
                    dist[e] = dist[x] + w;
                    s.insert({dist[e], e});
                }
            }
        }
        int M;
        M = INT_MIN;
        for(int i = 1; i <= N; i++)
        {
            //cout<<dist[i]<<" ";
            M = max(M, dist[i]);
        }
        return M == 1000000 ? -1 : M;
    }
};
