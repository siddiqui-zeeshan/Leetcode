class Solution {
public:
    int gcd(int a, int b) 
{  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    if (a == b) 
        return a; 
   
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        while(n > 1)
        {
            for(int i = 1; i < n; i++)
            {
                if(gcd(i, n) == 1)
                    res.push_back(to_string(i) + "/" + to_string(n));
            }
            n--;
        }
        return res;
    }
};
