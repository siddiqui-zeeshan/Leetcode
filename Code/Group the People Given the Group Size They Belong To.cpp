class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<vector<int>>> rec(501, vector<vector<int>> ());
        for(int i = 0; i < g.size(); i++)
        {
            if(rec[g[i]].empty())
            {
                rec[g[i]].push_back({i});
            }
            else
            {
                if(rec[g[i]][rec[g[i]].size() - 1].size() < g[i])
                {
                    rec[g[i]][rec[g[i]].size() - 1].push_back(i);
                }
                else
                {
                    rec[g[i]].push_back({i});
                }
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i <= 500; i++)
        {
            if(rec[i].empty())
                continue;
            for(int j = 0; j < rec[i].size(); j++)
            {
                res.push_back(rec[i][j]);
            }
            //res.push_back(rec[i]);
        }
        return res;
    }
};
