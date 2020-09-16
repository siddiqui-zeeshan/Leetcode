class Solution {
public:
    vector<int> productExceptSelf(vector<int>& A) {
        int n = A.size();
        vector<int> r(n, 1);
        vector<int> l(n, 1);
        for(int i = 1; i < n; i++)
        {
            l[i] = l[i-1] * A[i-1];
        }
        for(int i = n - 2; i >= 0; i--)
        {
            r[i] = r[i+1] * A[i+1];
        }
        
        vector<int> res(n, 1);
        for(int i = 0; i < n; i++)
        {
            res[i] = l[i]*r[i];
        }
        return res;
    }
};
