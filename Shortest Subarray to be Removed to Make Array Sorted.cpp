class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l, r;
        int n = arr.size();
        l = 0, r = n - 1;
        while(l + 1 < n && arr[l] <= arr[l + 1])
            l++;
        if(l == n - 1)
            return 0;
        while(r > l && arr[r] >= arr[r - 1])
            r--;
        int ans = min(n - l - 1, r);
        int i = 0, j = r;
        while(i <= l && j < n)
        {
            if(arr[i] <= arr[j])
            {
                ans = min(ans, j - i - 1);
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};
