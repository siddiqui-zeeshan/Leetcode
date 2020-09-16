class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++)
        {
            int n = i;
            bool flag = false;
            while(n)
            {
                int d = n % 10;
                if(d == 0 || i % d != 0)
                {
                    flag = true;
                    break;
                }
                n /= 10;
            }
            if(!flag)
                res.push_back(i);
        }
        return res;
    }
};
