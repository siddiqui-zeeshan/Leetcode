class Solution {
public:
    //vector<int> dp;
    int funct(int n, unordered_map<int, int> & mp, vector<int>& dp)
    {
        //cout<<n<<" ";
        if(n < 1000000)
            return dp[n];
        if(mp.find(n) != mp.end())
            return mp[n];
        int res;
        if(n % 6 == 0)
            res = 1 + min(funct(n / 3, mp, dp),  funct(n / 2, mp, dp));
        else if(n % 3 == 0)
            res = 1 + min(funct(n / 3, mp, dp),  funct(n - 1, mp, dp));
        else if(n % 2 == 0)
            res = 1 + min(funct(n - 1, mp, dp),  funct(n / 2, mp, dp));
        else 
            res = 1 + funct(n - 1, mp, dp);
        mp[n] = res;
        return res;
    }
    int minDays(int n) {
        //dp.resize(1000000);
        vector<int> dp(1000000, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 2;
        for(int i = 3; i < 1000000; i++)
        {
        
            if(i % 6 == 0)
            {
                dp[i] = 1 + min(dp[i / 3], min(dp[i - 1], dp[i / 2]));
            }
            else if(i % 2 == 0)
            {
                dp[i] = 1 + min(dp[i - 1], dp[i / 2]);
            }
            else if(i % 3 == 0)
            {
                dp[i] = 1 + min(dp[i - 1], dp[i / 3]);
            }
            else dp[i] = 1 + dp[i - 1];
        }
        unordered_map<int, int> mp;
        return funct(n, mp, dp);
    }
};
