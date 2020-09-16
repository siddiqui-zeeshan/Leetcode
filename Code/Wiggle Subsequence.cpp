class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        vector<int> dp(A.size(), 1);
        vector<int> rec(A.size(), 0);
        for(int i = 1; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(j == 0)
                {
                    if(A[i] > A[j])
                    {
                        rec[i] = 1;
                        dp[i]++;
                    }
                    else if(A[i] < A[j])
                    {
                        rec[i] = -1;
                        dp[i]++;
                    }
                }
                else
                {
                    //cout<<"a\n";
                    if(A[i] > A[j] && rec[j] == -1 && dp[j] + 1 > dp[i])
                    {
                        rec[i] = 1;
                        dp[i] = dp[j] + 1;
                    }
                    else if(A[i] < A[j] && rec[j] == 1 && dp[j] + 1 > dp[i])
                    {
                        //cout<<"b\n";
                        rec[i] = -1;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            
        }
        int m = 0;
            for(int i = 0; i < dp.size(); i++)
            {
                //cout<<dp[i]<<" "<<rec[i]<<endl;
                m = max(m, dp[i]);
            }
        return m;
    }
};
