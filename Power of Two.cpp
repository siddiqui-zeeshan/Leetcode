class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        int i,j;
        i=n;
        j=n-1;
        return !(i&j);
    }
};
