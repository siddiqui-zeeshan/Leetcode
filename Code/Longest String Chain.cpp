class Solution {
public:
    static bool comp(string &s, string &t)
    {
        return s.length() < t.length();
    }
    bool lcs(string w1, string w2) {
        vector<vector<int>> dp(w1.length() + 1, vector<int> (w2.length() + 1, 0));
        for(int i = 1; i <= w1.length(); i++)
        {
            for(int j = 1; j <= w2.length(); j++)
            {
                if(w1[i - 1] == w2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[w1.length()][w2.length()] == w1.length();
    }
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(), 1);
        sort(words.begin(), words.end(), comp);
        int ans = 1;
        for(int i = 1; i < words.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(words[j].size() != words[i].size() - 1)
                    continue;
                if(lcs(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};
