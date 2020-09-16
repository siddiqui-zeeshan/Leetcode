class Solution {
public:
    int fib(int N) {
        int a = 0;
        int b = 1;
        int i = 2;
        if(N == 0)
            return 0;
        if(N == 1)
            return 1;
        while(i <= N)
        {
            int c = a + b;
            a = b;
            b = c;
            i++;
        }
        return b;
    }
};
