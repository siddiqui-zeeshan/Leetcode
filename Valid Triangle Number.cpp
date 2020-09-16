class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++) {
            for(int j = i+1; j < n ; j++) {
                int sum = nums[i] + nums[j];
                auto it = lower_bound(nums.begin()+j+1, nums.end(), sum);
                count += distance(nums.begin()+j+1, it);
            }
        }
        return count;
    }
};
