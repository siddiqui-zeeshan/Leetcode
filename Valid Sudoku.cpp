class Solution {
public:
    bool rowSafe(vector<char> s)
{
    map<char, bool> rec;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!='.')
        {
        if(rec.find(s[i])!=rec.end())
        return false;
        rec.insert(pair<char,bool>(s[i],true));
        }
    }
    return true;
}
bool colSafe(const vector<vector<char>> &A, int row, int col)
{
    map<char, bool> rec;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i][col]!='.')
        {
        if(rec.find(A[i][col])!=rec.end())
        return false;
        rec.insert(pair<char,bool>(A[i][col],true));
        }
    }
    return true;
}
    bool boxSafe(const vector<vector<char>> &A, int row, int col)
{
    int sr=row-row%3;
    int sc=col-col%3;
    map<char, bool> rec;
    for(int i=sr; i<sr+3; i++)
    {
        for(int j=sc; j<sc+3; j++)
        {
            if(A[i][j]!='.')
            {
            if(rec.find(A[i][j])!=rec.end())
            {
                return false;
            }
            rec.insert(pair<char,bool>(A[i][j],true));
            }
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& A) {
        for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            bool a = rowSafe(A[j]);
            bool b = colSafe(A, i, j);
            bool c = boxSafe(A, i, j);
            //cout<<a<<" "<<b<<" "<<c<<"\n";
            if(!(a && b && c))
            return 0;
        }
    }
    return 1;
    }
};
