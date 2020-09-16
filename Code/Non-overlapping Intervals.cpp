class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& A) {
        if(A.size() < 2)
            return 0;
        sort(A.begin(), A.end(), comp);
        int res = 1;
        int e = A[0][1];
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i][0] >= e)
            {
                e = A[i][1];
                res++;
            }
        }
        return A.size() - res;
    }
};
