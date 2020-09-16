class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a, b, c;
        a = b = c = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(a == INT_MIN)
            {
                a = nums[i];
            }
            else if(a != INT_MIN && nums[i] < a)
            {
                a = nums[i];
            }
            else if(a != INT_MIN && b == INT_MIN && nums[i] > a)
            {
                b = nums[i];
            }
            else if(a != INT_MIN && b != INT_MIN && nums[i] > a && nums[i] < b)
            {
                b = nums[i];
            }
            else if(a != INT_MIN && b != INT_MIN && c == INT_MIN && nums[i] > b)
            {
                c = nums[i];
            }
            else if(a != INT_MIN && b != INT_MIN && c != INT_MIN && nums[i] > b && nums[i] < c)
            {
                c = nums[i];
            }
        }
        if(a < b && b < c && a != INT_MIN && b != INT_MIN && c != INT_MIN)
            return true;
        return false;
    }
};
