class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        map<char, int> rec;
    int count=0, fin=0;
    for(int i=0;i<A.length();i++)
    {
        if(rec.find(A[i])==rec.end())
        {
            
            count++;
            rec[A[i]]=i;
        }
        else
        {
            i=rec.find(A[i])->second+1;
            fin=max(fin,count);
            rec.clear();
            count=1;
            rec[A[i]]=i;
        }
        if(i==A.length()-1)
            {
                fin=max(fin,count);
            }
        
    }
    return fin;
        
    }
};
