class Solution {
public:
    int integerBreak(int n) {
        int t = n;
        int count = 0;
        if(n <= 3)
            return n - 1;
        while(t > 3)
        {
            t -= 3;
            count++;
        }
        count--;
        int n2 =  t + 3;
        int res = pow(3, count) *n2;
        int res2 = pow(3, count + 1) * (n2 - 3);
        return max(res, res2);
    }
};
