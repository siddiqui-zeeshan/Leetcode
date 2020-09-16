class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int B) {
        if( A.size()<4)
            return {};
    set<vector<int>> res;
    vector<int> rec;
    sort(A.begin(), A.end());
    unordered_set<int> s; 
    for(int i=0;i<A.size()-3;i++)
    {
        for(int j=i+1;j<A.size()-2;j++)
        {
            for(int k=j+1;k<A.size();k++)
            {
                int temp=B-(A[i]+A[j]);
                temp=temp-A[k];
                if (s.find(temp) != s.end())
                {
                    rec.push_back(A[i]);
                    rec.push_back(A[j]);
                    rec.push_back(*s.find(temp));
                    rec.push_back(A[k]);
                    res.insert(rec);
                    rec.clear();
                }
                s.insert(A[k]);
                
            }
            s.clear();
            
        }
    }
    vector<vector<int>> res1;
    for(auto i=res.begin();i!=res.end();i++)
    {
        res1.push_back(*i);
    }
    return res1;
}
};
