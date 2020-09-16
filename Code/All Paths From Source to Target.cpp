class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int cur)
    {
        path.push_back(cur);
        if(cur == graph.size() - 1)
        {
            res.push_back(path);
        }
        else for(int i = 0; i < graph[cur].size(); i++)
        {
            dfs(graph, res, path, graph[cur][i]);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(graph, res, path, 0);
        return res;
    }
};
