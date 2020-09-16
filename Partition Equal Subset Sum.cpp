class Solution {
public:
    vector<vector<int>> dp;
    bool check(vector<int> nums, int sum, int pos, int fin)
    {
        if(sum > fin)
            return false;
        if(sum == fin)
            return true;
        if(pos == nums.size())
        {
            if(sum == fin)
                return true;
            else
                return false;
        }
        if(dp[sum][pos] != -1)
            return dp[sum][pos] == 1 ? true : false;
        bool res = check(nums, sum + nums[pos], pos + 1, fin)
            || check(nums, sum, pos + 1, fin);
        dp[sum][pos] = res == true ? 1 : 0;
        return res;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
        {
            sum += i;
        }
        if(sum % 2 != 0)
            return false;
        vector<vector<int>> temp(sum, vector<int>(nums.size() + 10, -1));
        dp = temp;
        sum /= 2;
        return check(nums, 0, 0, sum);
    }
};
