class Solution {
public:
    unordered_map<int, int> dp;
    
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(dp.find(target) != dp.end())
            return dp[target];
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += combinationSum4(nums, target - nums[i]);
        }
        dp[target] = sum;
        return sum;
    }
};
