class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        double sum = 0;
        double avg = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i < k)
            {
                sum += nums[i];
            }
            if(i >= k)
            {
                avg = max(avg, sum / k);
                sum += nums[i] - nums[i - k];
            }
        }
        double a = sum / k;
        avg = max(avg, a);
        return avg;
    }
};
