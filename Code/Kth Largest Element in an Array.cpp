class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        multiset<int, greater<int>> rec;
        for(int i = 0; i<A.size();i++)
        {
            rec.insert(A[i]);
        }
        int pos = 1;
        for(auto i = rec.begin();i!=rec.end();i++)
        {
            if(pos == k)
            {
                return *i;
            }
            pos++;
        }
        return -1;
    }
};
