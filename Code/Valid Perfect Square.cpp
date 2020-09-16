class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0,u=num;
        while(l<=u)
        {
            long long int mid=(l+u)/2;
            if(mid*mid==num)
                return true;
            if(mid*mid>num)
                u=mid-1;
            else 
                l=mid+1;
        }
        return false;
    }
};
