class Solution {
public:
    vector<string> res;
    bool valid(string s)
    {
        //cout<<s<<endl;
        int n=s.length();
        string w="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.' || i==n-1)
            {
                if(i==n-1 && s[i]!='.')
                {
                    w+=s[i];
                }
                if(w.empty())
                    return false;
                if(w.size()>3)
                {
                    return false;
                }
                int x=stoi(w);
                if(x>255)
                    return false;
                if(to_string(x)!=w)
                    return false;
                w="";
            }
            else
            {
                w+=s[i];
            }
        }
        return true;
    }
    void backtracking(string s, int d, int pos)
    {
        
        if(d==3)
        {
            //cout<<s<<endl;
            if(valid(s))
                res.push_back(s);
                return;
        }
        for(int i=pos+1;i<s.length();i++)
        {
            if(i==s.length()-1 && d<2)
            return;
            s.insert(s.begin()+i, '.');
            backtracking(s, d+1, i);
            s.erase(s.begin()+i);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12)
            return {};
        res.clear();
        backtracking(s, 0, -1);
        return res;
    }
   
    
};
