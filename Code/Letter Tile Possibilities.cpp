class Solution {
public:
    void count(set<string> &rec, string &A, string &s, int l)
    {
        if(s.length()>=1 )
        {
            if(s.length()<=l)
                rec.insert(s);
            if(s.length()==l)
                return;
        }
        for(int i=0; i<A.length();i++)
        {
            s=s+A[i];
            char ch=A[i];
            A.erase(A.begin()+i);
            count(rec, A, s, l);
            s.pop_back();
            A.insert(A.begin()+i, ch);
        }
    }
    int numTilePossibilities(string A) {
        string s="";
        set<string> rec;
        int l=A.length();
        count(rec, A, s, l);
        
        return rec.size();
    }
};
