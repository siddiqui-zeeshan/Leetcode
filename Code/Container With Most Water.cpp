class Solution {
public:
    int maxArea(vector<int>& A) {
        int start=0;
        int end=A.size()-1;
        int vol=0;
        int maxv=0;
        while(start<end)
        {
            
            if(A[start]<A[end])
            {
                vol=abs(A[start])*(end-start);
                maxv=max(vol, maxv);
                start++;
            }
            else
            {
                vol=A[end]*(end-start);
                 maxv=max(vol, maxv);
                end--;
            }
        }
        return maxv;
    }
};
