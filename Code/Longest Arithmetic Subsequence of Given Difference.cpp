class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> dp;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            int d = arr[i] - diff;   
            if(dp.find(d) == dp.end())
            {
                if(dp.find(arr[i]) == dp.end())
                    dp[arr[i]] = 1;
            }
            else
            {
                if(dp.find(arr[i]) == dp.end())
                    dp[arr[i]] = dp[d] + 1;
                else
                    dp[arr[i]] = max(dp[arr[i]], dp[d] + 1);
            }
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
    
};
