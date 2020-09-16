class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    int dfs(int n, unordered_map<int, int>& dp)
    {
        if(n == 1)
            return 0;
        if(dp.find(n) != dp.end())
            return dp[n];
        if(n % 2 == 0)
           return dp[n] = 1 + dfs(n / 2, dp);
        else
            return dp[n] = 1 + dfs(3 * n + 1, dp);
        
    }
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> dp;
        vector<vector<int>> res;
        for(int i = lo; i <= hi; i++)
        {
            int a = dfs(i, dp);
            res.push_back({a, i});
        }
        sort(res.begin(), res.end(), comp);
        // for(auto i : res)
        // {
        //     cout<<i[1]<<" "<<i[0]<<endl;
        // }
        return res[k - 1][1];
    }
};
