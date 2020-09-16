class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l, r, m;
        l = 0;
        r = nums.size() - 1;
        while(l <= r)
        {
            m = (l + r) / 2;
            if(nums[m] == target)
                return true;
            if(nums[l] == nums[m] && nums[r] == nums[m])
            {
                r--;
                l++;
            }
            else if(nums[l] <= nums[m])
            {
                if(nums[l] <= target && nums[m] > target)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if(nums[m] < target && nums[r] >= target)
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return false;
    }
};
