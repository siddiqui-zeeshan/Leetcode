class Solution {
public:
    int myAtoi(string s) {
        long long num=0;
        int p=0;
        int n=s.length();
        while(s[p]==' ')
            p++;
        s=s.substr(p, n-p);
        n=s.length();
        int sign=s[0]=='-'?-1:1;
        if(s[0]=='-'|| s[0]=='+')
        {
            s=s.substr(1, n-1);
            n--;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                int x=s[i]-'0';
                num=num*10+x;
            }
            else
            {
                break;
            }
            if(num>INT_MAX)
            {
                break;
            }
        }
        num*=sign;
        //cout<<num;
        if(num>INT_MAX)
            return INT_MAX;
        if(num<INT_MIN)
            return INT_MIN;
        return num;
    }
};
