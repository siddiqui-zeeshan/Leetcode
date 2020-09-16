class Solution {
public:
    int find(vector<int>& dsu, int x)
    {
        if(dsu[x] != x)
        {
            dsu[x] = find(dsu, dsu[x]);
        }
        return dsu[x];
    }
    void _union(vector<int>& dsu, int x, int y)
    {
        int xp = find(dsu, x);
        int yp = find(dsu, y);
        if(xp != yp)
            dsu[xp] = yp;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> dsu(edges.size() + 1, 0);
        for(int i = 1; i < dsu.size(); i++)
        {
            dsu[i] = i;
        }
        
        for(int i = 0; i < edges.size(); i++)
        {
            int x = find(dsu, edges[i][0]);
            int y = find(dsu, edges[i][1]);
            
            if(x == y)
                return {edges[i][0], edges[i][1]};
            _union(dsu, x, y);
        }
        return vector<int>();
    }
};
