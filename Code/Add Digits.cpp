class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while(sum > 9)
        {
            if(num == 0)
                num = sum;
            sum = 0;
            while(num != 0)
            {
                int d = num % 10;
                sum += d;
                num /= 10;
            }
        }
        return sum;
    }
};
