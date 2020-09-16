class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        ans.clear();
        vector<int> indeg(n, 0);
        for(int i = 0; i < p.size(); i++)
        {
            int a = p[i][1];
            int b = p[i][0];
            adj[a].push_back(b);
            indeg[b]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indeg[i] == 0){
                q.push(i);
                ans.push_back(i);
        }
        }
        int vis = 0;
        
        while(!q.empty())
        {
            vis++;
            int v = q.front();
            q.pop();
            
            for(int i = 0; i < adj[v].size(); i++)
            {
                --indeg[adj[v][i]];
                if(indeg[adj[v][i]] == 0){
                    ans.push_back(adj[v][i]);
                    q.push(adj[v][i]);
                }
            }
        }
        return vis == n ? ans : vector<int>();
    }
};
