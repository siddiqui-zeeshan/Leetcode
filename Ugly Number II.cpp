class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        
        int a, b, c;
        a = b = c = 0;
        vector<int> k(n);
        k[0] = 1;
        for(int i = 1; i < n; i++)
        {
            k[i] = min(k[a] * 2, min(k[b] * 3, k[c] * 5));
            
            if(k[i] == k[a] * 2)
                a++;
            if(k[i] == k[b] * 3)
                b++;
            if(k[i] == k[c] * 5)
                c++;
            
        }
        return k[n-1];
    }
};
