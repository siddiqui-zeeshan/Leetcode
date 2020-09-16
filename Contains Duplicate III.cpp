class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
        
        if(A.size() == 0)
            return false;
        
        map<int, int> rec;
        rec[A[0]]++;
        int l = 0; 
        int r = 1;
        long diff = LONG_MAX;
        while(r < A.size())
        {
            if(r - l <= k)
            {
                rec[A[r]]++;
                auto itr = rec.find(A[r]);
                if(rec[A[r]] > 1)
                    diff = 0;
                long d1 = LONG_MAX;
                long d2 = LONG_MAX;
                if(itr != rec.begin())
                {
                    itr--;
                    d1 = min(d1, (long)((long)A[r] - itr->first));
                }
                itr = rec.find(A[r]);
                itr++;
                if(rec.find(A[r]) != rec.end() && itr != rec.end())
                {
                    //itr++;
                    d2 = min(d2, (long)((long)itr->first - A[r]));
                }
                cout<<d1<<" "<<d2<<endl;
                diff = min(diff, min(d1, d2));
                r++;
            }
            else
            {
                rec[A[l]]--;
                if(rec[A[l]] == 0)
                    rec.erase(A[l]);
                l++;
                rec[A[r]]++;
                
                if(rec[A[r]] > 1)
                    diff = 0;
                
                auto itr = rec.find(A[r]);
                long d1 = LONG_MAX;
                long d2 = LONG_MAX;
                if(itr != rec.begin())
                {
                    itr--;
                    d1 = min(d1, (long)((long)A[r] - itr->first));
                }
                itr = rec.find(A[r]);
                itr++;
                if(rec.find(A[r]) != rec.end() && itr != rec.end())
                {
                    //itr++;
                    d2 = min(d2, (long)((long)itr->first - A[r]));
                }
                cout<<d1<<" "<<d2<<endl;
                diff = min(diff, min(d1, d2));
                r++;
            }
        }
        cout<<diff<<endl;
        return diff <= t;
    }
};
