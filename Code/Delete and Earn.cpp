class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty())
            return 0;
        map<int,int> rec;
        for(auto i : nums)
            rec[i]++;
        vector<vector<int>> dp;
        auto itr = rec.begin();
        for(int i = 0; i < 20000; i++)
        {
            if(itr != rec.end() && i == itr->first)
            {
                dp.push_back({itr->first, itr->second});
                itr++;
            }
            else
            {
                dp.push_back({i, 0});
            }
        }
        int ns = 0;
        int s = dp[0][0] * dp[0][1];
        for(int i = 1; i < dp.size(); i++)
        {
            int st, nst;
            st = ns + dp[i][0] * dp[i][1];
            nst = max(s, ns);
            ns = nst;
            s = st;
        }
        return max(ns, s);
    }
};
