class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        for(int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int l, r;
            l = i + 1;
            r = nums.size() - 1;
            while(l < r)
            {
                if(target > nums[l] + nums[r])
                    l++;
                else if(target < nums[l] + nums[r])
                    r--;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    int t = nums[l];
                    while(l < r && t == nums[l])
                        l++;
                    t = nums[r];
                    while(r > l && t == nums[r])
                        r--;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};
