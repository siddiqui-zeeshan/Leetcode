class Solution {
public:
    string countAndSay(int A) {
        string s="1";
    if(A==1)
    return s;
    A--;
    string t="";
    char store=s[0];
    int count=0;
    while(A)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==store)
            {
                count++;
            }
            if(s[i]!=store || i==s.length()-1)
            {
                t=t+to_string(count)+store;
                if(s[i]!=store && i==s.length()-1)
                {
                    store=s[i];
                    count=1;
                    t=t+to_string(count)+store;
                }
                store=s[i];
                count=1;
                
            }
        }
        //cout<<t<<"\n";
        s=t;
        t="";
        A--;
        store=s[0];
        count=0;
    }
    return s;
    }
};
