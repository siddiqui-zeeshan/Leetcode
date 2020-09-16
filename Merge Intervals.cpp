class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        if(!A.size())
            return {};
        sort(A.begin(), A.end());
        vector<vector<int>> res;
        int s, e;
        s=A[0][0];
        e=A[0][1];
        int n=A.size();
        for(int i=1;i<n;i++)
        {
            
            if(e>=A[i][0])
            {
                e=max(e, A[i][1]);
            }
            else
            {
                vector<int> temp;
                temp.push_back(s);
                temp.push_back(e);
                res.push_back(temp);
                s=A[i][0];
                e=A[i][1];
            }
        }
        vector<int> temp;
        temp.push_back(s);
        temp.push_back(e);
        res.push_back(temp);
        return res;
    }
};
