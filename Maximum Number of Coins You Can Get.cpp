class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int ans = 0;
        int r = n - 2;
        for(int i = 0; i < n / 3; i++)
        {
            ans += piles[r];
            r-= 2;
        }
        return ans;
    }
};
