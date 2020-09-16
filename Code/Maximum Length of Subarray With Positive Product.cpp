class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negct = 0;
        int start = 0; 
        int neg1 = -1;
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                start = i + 1;
                negct = 0;
                neg1 = -1;
            } 
            else
            {
                if(nums[i] < 0)
                {
                    negct++;
                }
                if(negct == 1 && neg1 == -1)
                {
                    neg1 = i;
                }
                if(negct % 2 == 0)
                {
                    res = max(i - start + 1, res);   
                }
                else
                {
                    res = max(i - neg1, res);
                }
            }
        }
        return res;
    }
};
