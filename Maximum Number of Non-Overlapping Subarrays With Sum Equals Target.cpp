class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
       unordered_map<int, int> dp;
        int left, right;
        right = -1;
        dp[0] = -1;
        int sum = 0;
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(dp.count(sum - target))
            {
                int left = dp[sum - target];
                if(left >= right)
                {
                    count++;
                    right = i;
                }
            }
            dp[sum] = i;
        }
        return count;
    }
};
