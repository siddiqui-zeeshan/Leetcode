class Solution {
public:
    bool dfs(int p, vector<int>& arr, vector<bool>& vis)
    {
        vis[p] = true;
        if(arr[p] == 0)
            return true;
        int l = p - arr[p];
        int r = p + arr[p];
        if(l >= 0 && !vis[l] && dfs(l, arr, vis))
            return true;
        if(r < arr.size() && !vis[r] && dfs(r, arr, vis))
            return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return dfs(start, arr, vis);
    }
};
