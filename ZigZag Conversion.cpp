class Solution {
public:
    string convert(string s, int l) {
        vector<string> rec(l);
        int n=s.length();
        for(int i=0;i<l;i++)
        {
            string x(n, '*');
            rec[i]=x;
        }
        int x=0;
        int p=0;
        while(p<n)
        {
            int i=0;
            while(i<l && p<n)
            {
                rec[i][x]=s[p];
                i++;
                p++;
            }
            i-=2;
            x++;
            while(i>0 && p<n)
            {
                rec[i][x]=s[p];
                i--;
                x++;
                p++;
            }
        }
        string t="";
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<n;j++)
            {
                //cout<<rec[i][j];
                if(rec[i][j]!='*')
                {
                    t=t+rec[i][j];
                }
            }
            //cout<<endl;
        }
        return t;
    }
};
