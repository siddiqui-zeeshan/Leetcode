class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[m])
                m = i;
        }
        for(auto i : nums)
        {
            if(nums[m] != i && 2 * i > nums[m])
                return -1;
        }
        return m;
    }
};
