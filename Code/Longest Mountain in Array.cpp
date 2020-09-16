class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size()==0)
            return 0;
        A.insert(A.begin(), INT_MAX);
        A.insert(A.end(), INT_MAX);
        int maxs=0;
        int size=0;
        for(int i=1;i<A.size()-1;i++)
        {
            if(A[i]>A[i-1] && A[i]>A[i+1])
            {
                //cout<<i<<"\n";
                int r=i+1, l=i-1;
                while(l>0 && r<(A.size()-1))
                {
                    if(r<A.size()-1 && A[r]>A[r+1])
                    r++;
                    if(l>0 && A[l]>A[l-1])
                    l--;
                    if(A[r]<=A[r+1] && A[l]<=A[l-1])
                        break;
                }
                //cout<<l<<" "<<r<<" ";
                size=r-l+1;
                maxs=max(maxs, size);
            }
        }
        return maxs;
    }
};
