class Solution {
public:
    int mySqrt(int x) {
        int l=0,u=x;
        long long mid;
        while(l<=u)
        {
            mid=(l+u)/2;
            if(mid*mid==x)
                return mid;
            if(mid*mid<x)
                l=mid+1;
            else
                u=mid-1;
        }
        if(mid*mid<x)
        return mid;
        else
        return --mid;
    }
};
