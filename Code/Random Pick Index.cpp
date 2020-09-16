class Solution {
public:
    unordered_map<int, vector<int>> rec;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            rec[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = rec[target].size();
        int pos = rand() % size;
        return rec[target][pos];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
