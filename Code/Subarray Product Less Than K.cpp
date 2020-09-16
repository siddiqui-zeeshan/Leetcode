class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int s) {
        if (s <= 1) return 0;
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            while (prod >= s) {
                
                
                prod /= nums[left++];
                
            }
ans += i - left +1;
        }
        return ans;
    }
};
