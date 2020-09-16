class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] == 0 ? -1 : 1;
        }
        unordered_map<int, int> rec;
        rec[nums[0]] = 0;
        int len = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
            if(rec.find(nums[i]) == rec.end())
            {
                rec[nums[i]] = i;
            }
            else
            {
                len = max(len, i - rec[nums[i]]);
            }
            if(nums[i] == 0)
            {
                len = max(len, i + 1);
            }
        }
        return len;
    }
};
