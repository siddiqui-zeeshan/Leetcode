class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        vector<int> temp=A;
        sort(temp.begin(), temp.end());
        int s=0, e=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=temp[i])
            {
                s=i;
                break;
            }
        }
        for(int i=A.size()-1; i>=0;i--)
        {
            if(A[i]!=temp[i])
            {
                e=i;
                break;
            }
        }
        if(s<e)
        return(e-s+1);
        else
            return 0;
    }
};
