class Solution {
public: 
    int numWays(string s) {
        int one = 0;
        for(auto i : s)
        {
            one = i == '1' ? one + 1 : one;
        }
        if(one % 3 != 0)
            return 0;
        if(one == 0)
        {
            long res =  ((long)s.length() - 1) * ((long)s.length() - 2) / 2;
            return (int)(res % 1000000007);
        }
        one /= 3;
        int zero1 = 0;
        int oc = 0;
        for(auto i : s)
        {
            if(i == '0' && oc == one)
            {
                zero1++;
            }
            else if(i == '1')
            {
                oc++;
            }
        }
        int zero2 = 0;
        oc = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '0' && oc == one)
            {
                zero2++;
            }
            else if(s[i] == '1')
                oc++;
        }
        long res =  (((long)zero1 + 1) % 1000000007 * ((long)zero2 + 1) % 1000000007) % 1000000007;
        return (int) res;
    }
};
