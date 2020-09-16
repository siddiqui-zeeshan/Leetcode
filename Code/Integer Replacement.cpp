class Solution {
public:
    unordered_map<long, int> dp;
    long num;
    int func(long n)
    {
        cout<<n<<" ";
        if(n <= 1)
            return 0;
        if(dp.find(n) != dp.end())
            return dp[n];
        int step = 0;
        if(n % 2 == 0)
            step = 1 + integerReplacement(n / 2);
        else
            step = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        dp[n] = step;
        return step;
    }
    int integerReplacement(int n) {
        num = n;
        return func((long)n);
    }
};
