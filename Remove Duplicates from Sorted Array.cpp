class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int n=A.size();
        if(n==0)
            return 0;
        int l, r;
        l=r=1;
        int count=1;
        while(r<n)
        {
            if(A[r]==A[r-1])
            {
                //do nothing
            }
            else
            {
                A[l]=A[r];
                l++;
                count++;
            }
            r++;
        }
        return count;
    }
};
