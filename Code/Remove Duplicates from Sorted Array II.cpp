class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int p1=0;
        int p2=1;
        int count=1;
        while(p2<A.size())
        {
            if(A[p1]==A[p2])
            {
                count++;
                if(count>2)
                {
                    A.erase(A.begin()+p2);
                }
                else
                    p2++;
            }
            else if(A[p1]!=A[p2])
            {
                p1=p2;
                p2++;
                count=1;
            }
        }
        return A.size();
    }
};
