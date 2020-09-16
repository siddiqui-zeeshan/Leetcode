class Solution {
public:
    int trailingZeroes(int n) {
        long x = 5;
        int sum = 0;
    
        int i = 2;
        while(n / x > 0)
        {
            sum += n/x;
            x = pow(5, i);
            i++;
        }
        
        return sum;
    }
};
