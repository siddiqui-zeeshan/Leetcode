class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        vector<string> res;
        if(A.size() == 0)
            return res;
        int st, en;
        st = 0;
        
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i] == A[i - 1] + 1)
            {
                
            }
            else if(A[i] != A[i - 1] + 1)
            {
                string w = "";
                if(st < i - 1)
                    w = to_string(A[st]) + "->" + to_string(A[i - 1]);
                else
                    w = to_string(A[st]);
                st = i;
                res.push_back(w);
                    
            }
        }
        string w = "";
        if(st < A.size() - 1)
            w = to_string(A[st]) + "->" + to_string(A[A.size() - 1]);
        else
            w = to_string(A[st]);
        res.push_back(w);
        return res;
    }
};
