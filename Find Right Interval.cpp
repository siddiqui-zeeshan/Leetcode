class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& A) {
        multimap<int, int> rec;
        for(int i = 0; i < A.size(); i++)
        {
            rec.insert({A[i][0], i});
        }
        vector<int> res;
        for(int i = 0; i < A.size(); i++)
        {
            bool flag = false;
            auto it = rec.lower_bound(A[i][1]);
            // while(it != rec.end())
            // {
            //     if(it->second > i)
            //     {
            //         flag = true;
            //         break;
            //     }
            //     it++;
            // }
            if(it != rec.end())
                flag = true;
            if(!flag)
            {
                it = rec.upper_bound(A[i][1]);
                if(it != rec.end())
                flag = true;
                // while(it != rec.end())
                // {
                //     if(it->second > i)
                //     {
                //         flag = true;
                //         break;
                //     }
                //     it++;
                // }
                
            }
            if(flag)
            {
                res.push_back(it->second);
            }
            else
                res.push_back(-1);
        }
        return res;
    }
};
