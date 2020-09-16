class Solution {
public:
    int msum;
    bool dfs(int pos, int sum[], vector<int> &A)
    {
        //cout<<pos<<endl;
        if(pos == A.size())
        {
            if(sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3])
                return true;
            else
                return false;
        }
        for(int i = 0; i < 4; i++)
        {
            if(sum[i] + A[pos] <= msum)
            {
                sum[i] += A[pos];
                if(dfs(pos + 1, sum, A))
                    return true;
                sum[i] -= A[pos];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int sum[4] = {0,0,0,0};
        msum = 0;
        
        for(auto i : nums)
        {
            msum += i;
        }
        if(msum % 4 != 0 || msum == 0)
            return false;
        sort(nums.begin(), nums.end(), greater<int>());
        msum /= 4;
        return dfs(0, sum, nums);
    }
};
