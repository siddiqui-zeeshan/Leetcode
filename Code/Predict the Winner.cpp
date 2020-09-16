class Solution {
public:
    int dfs(vector<int> &nums, int r, int l, int turn) {
        if(l == r)
        {
            return nums[l] * turn;
        }
        int a = turn * nums[l] + dfs(nums, r, l + 1, -turn);
        int b = turn * nums[r] + dfs(nums, r - 1, l, -turn);
        
        return turn * max(turn * a, turn * b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return dfs(nums, nums.size() - 1, 0, 1) >= 0;
    }
};
