class Solution {
    public double myPow(double x, int n) { 
        if (n == Integer.MIN_VALUE) {
            return myPow(1 / x, Integer.MAX_VALUE) * 1 / x;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        if (n == 0) {
            return 1;
        }
    
        return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x, n - 1);
    }
}
