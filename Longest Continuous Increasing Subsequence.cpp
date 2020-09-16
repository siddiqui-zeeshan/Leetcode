class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
                dp[i] += dp[i - 1];
            else
                dp[i] = 1;
        }
        int m = 0;
        for(auto i : dp)
            m = max(i, m);
        return m;
    }
};
