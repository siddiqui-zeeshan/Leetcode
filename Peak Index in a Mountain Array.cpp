class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int s=A.size();
        int l=1;
        int u=s-1;
        int ans=0;
        while(l<=u)
        {
            int mid=(l+u)/2;
            if(A[mid]>A[mid-1] && A[mid]>A[mid+1])
            {
                ans=mid;
                break;
            }
            else if(A[mid]>A[mid-1] && A[mid]<A[mid+1])
                    {
                        l=mid+1;
                    }
            else if(A[mid]<A[mid-1] && A[mid]>A[mid+1])    
                    {
                        u=mid-1;
                    }
        }
        return ans;
    }
};
