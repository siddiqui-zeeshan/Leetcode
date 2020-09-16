class Solution {
public:
    bool canJump(vector<int>& A) {
        int mxj=0;
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            if(mxj<i)
                return false;
            mxj=max(mxj, i+A[i]);
        }
        if(mxj>=A.size()-1)
            return true;
        else
            return false;
    }
};
