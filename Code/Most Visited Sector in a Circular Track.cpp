class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans(n + 1, 0);
        int m = rounds.size();
        for(int i = 0; i < m; i++)
        {
            rounds[i]--;
        }
        for(int i = 0; i < m - 1; i++)
        {
            for(int j = rounds[i]; j != rounds[i + 1]; j = (j + 1) % n)
            {
                ans[j]++;
            }
        }
        ans[rounds[m - 1]]++;
        int maximum = 0;
        for(auto i : ans)
        {
            //cout<<i<<" ";
            maximum = max(maximum, i);
        }
        vector<int> res ;
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] == maximum)
                res.push_back(i + 1);
        }
        return res;
    }
};
