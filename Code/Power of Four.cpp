class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        num--;
        int count=0,d=0;
        int temp=num;
        while(num)
        {
            
            num=num & (num-1);
            count++;
        }
        while(temp)
        {
            temp=temp>>1;
            d++;
        }
        if(d==count && count%2==0)
            return true;
        else 
            return false;
    }
};
