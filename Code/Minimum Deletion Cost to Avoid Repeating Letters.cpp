class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int l = s.length();
        int count = 0;
        int minC = INT_MIN;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < l; i++)
        {
            count++;
            minC = max(minC, cost[i]);
            sum += cost[i];        
            if(i < l - 1 && s[i] != s[i + 1])
            {
                //cout<<s[i]<<" "<<count<<endl;
                if(count > 1)
                {
                    ans += sum - minC;
                }
                count = 0;
                minC = INT_MIN;
                sum = 0;
            }
        }
        //cout<<sum<<" "<<count<<" "<<minC<<endl;
        if(count > 1)
        {
            ans += sum - minC;
        }
        return ans;
    }
};
