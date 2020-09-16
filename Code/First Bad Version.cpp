// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,u=n;
        long long int mid;
        while(l<u)
        {
            mid=l+(u-l)/2;
            if(isBadVersion(mid))
                u=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
