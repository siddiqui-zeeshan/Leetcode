class Solution {
public:
    int arrangeCoins(int n) {
       int l=0,u=n;
        long long mid;
       while(l<=u)
       {
           mid=(l+u)/2;
           if((mid*(mid+1))/2==n)
               return mid;
           if((mid*(mid+1))/2>n)
               u=mid-1;
           else
               l=mid+1;
       }
        if((mid*(mid+1))/2>n)
        return --mid;
        else 
            return mid;
    }
};
