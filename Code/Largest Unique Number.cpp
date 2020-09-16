class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        map<int, int > rec;
        for(int i=0;i<A.size();i++)
        {
            rec[A[i]]++;
        }
        int result=-1;
        for(auto i=rec.begin(); i!=rec.end(); i++)
        {
            if(i->second==1)
                result=i->first;
        }
        return result;
    }
};
