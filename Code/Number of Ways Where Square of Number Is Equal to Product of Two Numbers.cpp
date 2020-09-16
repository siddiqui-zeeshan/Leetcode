class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1, m2;
        for(auto i : nums1)
            m1[i]++;
        for(auto i : nums2)
            m2[i]++;
        int count = 0;
        for(auto i : nums1)
        {
            for(auto j : nums2)
            {
                long n = (long)i * (long)i;
                if(n % j == 0)
                {
                    //cout<<i<<"\n";
                    int m = n / j;
                    if(m2.find(m) != m2.end())
                    {
                        count += m2[m];
                        if(m == j)
                            count--;
                        //cout<<"-"<<count<<endl;
                    }
                }
            }
        }
        //count /= 2;
        for(auto i : nums2)
        {
            for(auto j : nums1)
            {
                long n = (long)i * (long)i;
                if(n % j == 0)
                {
                    //cout<<i<<"\n";
                    int m = n / j;
                    if(m1.find(m) != m1.end())
                    {
                        count += m1[m];
                        if(m == j)
                            count--;
                        //cout<<"-"<<count<<endl;
                    }
                }
            }
        }
        count /= 2;
        return count;
    }
};
