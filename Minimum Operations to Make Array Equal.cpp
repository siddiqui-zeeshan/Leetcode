class Solution {
public:
    int minOperations(int n) {
        if(n <= 1)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int r = 2 * n - 1;
        int mid = (r + 1) / 2;
        int steps = 0;
        for(int i = 0; i < n / 2; i++)
        {
            steps += mid - (2 * i + 1);
        }
        return steps;
    }
};
