class Solution {
public:
    void bracket(string &s, vector<string>& res, int& A)
{
    if(s.length()==2*A)
    {
        int sum=0;
        int flag=0;
        for(int i=0;i<2*A;i++)
        {
            if(s[i]=='(')
            sum++;
            if(s[i]==')')
            sum--;
            if(sum<0)
            {
                flag++;
            }
        }
        if(sum==0 && flag==0)
        res.push_back(s);
        return;
    }
    for(int i=0;i<2;i++)
    {
        if(i==0)
        s=s+"(";
        else
        s=s+")";
        bracket(s, res, A);
        s.pop_back();
    }
    
}
    vector<string> generateParenthesis(int A) {
        string s="";
    vector<string> res;
    bracket(s,res,A);
    return res;
    }
};
