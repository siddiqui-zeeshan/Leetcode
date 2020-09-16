class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
        }
        
        int res=1;
        int l=1;
        while(l<n)
        {
            int i=0;
            while(i+l<n)
            {
                int j=i+l;
                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
                }
                res=max(res, dp[i][j]);
                i++;
                
            }
            l++;
        }/*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j];//=0;
            }
            cout<<"\n";
        }*/
        return res;
    }
};
