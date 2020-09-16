class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& A) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        vector<int> rec(A.size(), 0);
        vector<int> k(n + 1);
        k[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            int x = k[rec[0]] * A[0];
            for(int j = 1; j < A.size(); j++)
            {
                x = min(k[rec[j]]* A[j], x);
            }
            k[i] = x;
            for(int j = 0; j < A.size(); j++)
            {
                if(k[i] == k[rec[j]] * A[j])
                    rec[j]++;
            }
            cout << k[i] <<" ";
        }
        return k[n-1];
    }
};
