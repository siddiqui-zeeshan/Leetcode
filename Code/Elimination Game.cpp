class Solution {
public:
    int lr(int n)
    {
        if(n == 1)
            return n;
        
        return 2 * rl(n/2);
    }
    int rl(int n)
    {
        if(n == 1)
            return n;
        
        if(n % 2 == 0)
            return 2 * lr(n/2) - 1;
        else
            return 2 * lr(n / 2);
    }
    
    int lastRemaining(int n) {
        return lr(n);
    }
};
