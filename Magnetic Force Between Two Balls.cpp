class Solution {
public:
    int maxDistance(vector<int>& a, int c) {
        int l=1;
        int u=1000000000;
        int ans;
        sort(a.begin(), a.end());
        int n = a.size();
        while(l<=u)
        {
            int mid= (l+u)/2;
            int temp=1;
            int fi=a[0];
            for(int i=1;i<n;i++)
            {
                if((a[i]-fi) >= mid)
                {
                    temp++;
                    fi=a[i];
                }
            }
            if(temp<c)
            u=mid-1;
            else
            {
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};
