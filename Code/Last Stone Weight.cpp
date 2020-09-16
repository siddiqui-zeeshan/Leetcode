class Solution {
public:
    int lastStoneWeight(vector<int>& A) {
        multimap<int,int,greater<int>> rec;
        for(int i=0;i<A.size();i++)
        {
            rec.insert(pair<int,int>(A[i],0));
            
        }
        while(rec.size()>1)
        {
            int x=rec.begin()->first;
            rec.erase(rec.begin());
            int y=rec.begin()->first;
            rec.erase(rec.begin());
            if(x!=y)
            {
                x=abs(x-y); 
                rec.insert(pair<int,int>(x,0));
            }
        }
        if(rec.size()==0)
            return 0;
        else
            return rec.begin()->first;
    }
};
