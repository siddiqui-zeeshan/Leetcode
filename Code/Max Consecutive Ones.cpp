class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int m = 0;
        for(auto i : nums)
        {
            if(i == 1)
            {
                count++;
            }
            else
            {
                m = max(count, m);
                count = 0;
            }
        }
        m = max(count, m);
        return m;
    }
};
