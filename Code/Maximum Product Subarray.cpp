class Solution {
public:
    int maxProduct(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        int M, m;
        M = m = A[0];
        int res = A[0];
        for(int i = 1; i < A.size(); i++)
        {
        
            int cM = max(A[i], max(M * A[i], m * A[i]));
            int cm = min(A[i], min(m * A[i], M * A[i]));
            res = max(res, cM);
            M = cM;
            m = cm;
            
        }
        return res;
    }
};
