class Solution {
public:
    int minOperations(vector<int>& nums) {
        int div, mdiv;
        div = mdiv = 0;
        int count = 0;
        for(auto i : nums)
        {
            int div = 0;
            int n = i;
            while(n > 0)
            {
                if(n % 2 == 0)
                {
                    n /= 2;
                    div++;
                    if(div > mdiv)
                    {
                        mdiv = div;
                        count++;
                    }
                }
                else 
                {
                    n--;
                    count++;
                }
            }
        }
        return count;
    }
};
