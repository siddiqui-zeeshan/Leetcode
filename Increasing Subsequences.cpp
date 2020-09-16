class Solution {
public:
    void dfs(vector<int>& A, set<vector<int>>& rec, vector<int>& v, int pos)
    {
        if(pos == A.size())
        {   
            if(v.size() > 1)
                rec.insert(v);
            return;
        }
        if(v.size() > 1)
            rec.insert(v);
        dfs(A, rec, v, pos + 1);
        if((!v.empty() && A[pos] >= v[v.size() - 1]) || (v.empty()))
        {
            v.push_back(A[pos]);
            dfs(A, rec, v, pos + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> rec;
        vector<int> v;
        dfs(nums, rec, v, 0);
        vector<vector<int>> res;
        for(auto i : rec)
        {
            res.push_back(i);
        }
        return res;
    }
};
