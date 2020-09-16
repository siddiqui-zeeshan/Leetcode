class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i = 0, counter = 0;
        int left = 1, right = n - 1, mid = 0;
        
        while (left < right)
        {
            mid = left + (right - left) / 2;
            
            counter = 0;
            for (i = 0; i < n; ++i)
            {
                if (nums[i] <= mid)
                    ++counter;
            }
            
            if (counter > mid)
                right = mid;
            else 
                left = mid + 1;
        }
        
        return left;
    }
};
