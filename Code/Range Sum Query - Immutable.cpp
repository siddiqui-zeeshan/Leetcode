class NumArray
{
public:
    vector<int> rec;
    NumArray(vector<int> &nums)
    {
        rec.clear();
        if(nums.size()>0)
        {
        vector<int> t(nums.size(), 0);
        t[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            t[i] += t[i - 1] + nums[i];
        }
        rec = t;
        }
    }

    int sumRange(int i, int j)
    {
        if (i == 0)
            return rec[j];
        else
        {
            return rec[j] - rec[i - 1];
        }
    }
};
