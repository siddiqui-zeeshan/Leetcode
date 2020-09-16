class Solution {
public:
    int res;
    int dfs(vector<int>& nums, int s, int S, int poi, string sign, vector<vector<int>>& rec)
    {
        if(poi == nums.size())
        {
            if(s == S)// && rec.find(sign) == rec.end())
                return 1;
            return 0;
        }
        if(rec[poi][s + 1000] != INT_MIN)
        {
            return rec[poi][s + 1000];
        }
        int a = dfs(nums, s + nums[poi], S, poi + 1, sign, rec);
        
        int b = dfs(nums, s - nums[poi], S, poi + 1, sign, rec);
        return rec[poi][s + 1000] = a + b;
                
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        bool flag = false;
        for(auto i : nums)
        {
            if(i != 0)
                flag = true;
        }
        if(flag == false)
        {
            if(S != 0)
                return 0;
            else
                return pow(2, nums.size());
        }
        res = 0;
        vector<vector<int>> rec(nums.size() + 10, vector<int>(2010, INT_MIN));
        return dfs(nums, 0, S, 0, "", rec);
    }
};
