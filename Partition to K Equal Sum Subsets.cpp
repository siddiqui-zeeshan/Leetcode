class Solution {
public:
    bool recur(vector<int>& A, vector<int>& nums, int sum, int pos)
    {
        if(pos == nums.size())
        {
            int flag = true;
            for(auto i : A)
                if(i != sum)
                    flag = false;
            return flag;
        }
        
        for(int i = 0; i < A.size(); i++)
        {
            if(nums[pos] + A[i] <= sum )
            {
                A[i] += nums[pos];
                if(recur(A, nums, sum, pos + 1))
                {
                    //A[i] -= nums[pos];
                    return true;
                }
                A[i] -= nums[pos];
            }
            if(A[i] == 0)
                break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for(auto i : nums)
            sum += i;
        if(sum % k != 0)
            return false;
        sum /= k;
        vector<int> A(k, 0);
        return recur(A, nums, sum, 0);
    }
};
