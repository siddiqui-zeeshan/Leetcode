class Solution {
public:
    void dfs(vector<int> &path, vector<vector<int>> &res, int pos, int n, int k)
    {
        if(path.size() == k)
        {
            int sum = 0;
            for(auto i : path)
                sum += i;
            if(sum == n)
                res.push_back(path);
            return;
        }
        for(int i = pos; i <= 9; i++)
        {
            path.push_back(i);
            dfs(path, res, i + 1, n, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(path, res, 1, n, k);
        return res;
    }
};
