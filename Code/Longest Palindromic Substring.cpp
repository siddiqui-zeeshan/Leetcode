class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        vector<vector<bool>> dp(l, vector<bool>(l, 0));
        int maxlen = 1;
        for(int i = 0; i < l; i++)
        {
            dp[i][i] = 1;
        }
        int start = 0;
        for(int i = 0; i < l - 1; i++)
        {
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                maxlen = 2;
                start = i;
            }
        }
        for(int k = 3; k <= l; k++)
        {
            for(int i = 0; i < l - k + 1; i++)
            {
                int j = i + k - 1;
                if(dp[i + 1][j - 1] && s[i] == s[j])
                {
                    dp[i][j] = 1;
                    if(k > maxlen)
                    {
                        maxlen = k;
                        start = i;
                    }
                }
                
            }
        }
        return s.substr(start, maxlen);
    }
};
