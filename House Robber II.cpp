class Solution {
public:
    int util(vector<int>& A, int s, int e)
    {
        int prev, nprev;
        prev = nprev = 0;
        prev = A[s];
        for(int i = s + 1; i < e; i++)
        {
            int Nprev = prev;
            int Nnprev = nprev;
            Nnprev = max(nprev, prev);
            Nprev = max(nprev + A[i], prev);
            prev = Nprev;
            nprev = Nnprev;
        }
        return max(prev, nprev);
    }
    int rob(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        if(A.size() == 1)
            return A[0];
        return max(util(A, 0, A.size() - 1), util(A, 1, A.size()));
    }
};
