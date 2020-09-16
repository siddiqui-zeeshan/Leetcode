class Solution {
public:
    int dfs(vector<int>& nums, vector<bool>& vis, int pos)
    {
        if(vis[pos])
            return 0;
        vis[pos] = true;
        return dfs(nums, vis, nums[pos]) + 1;
    }
    int arrayNesting(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count = max(count, dfs(nums, vis, nums[i]));
        }
        return count;
    }
};
