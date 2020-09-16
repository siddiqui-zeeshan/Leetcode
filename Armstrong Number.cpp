class Solution {
public:
    bool isArmstrong(int N) {
        long long int sum=0;
        int num=N;
        int c=0;
        while(num)
        {
            c++;
            num=num/10;
        }
        num=N;
        while(num)
        {
            sum=sum+pow(num%10, c);
            num=num/10;
        }
        
        return (sum==N);
    }
};
