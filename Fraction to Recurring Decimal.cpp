class Solution {
public:
    string fractionToDecimal(int numr, int denr) {
        string sign = "";
        long nr = ((long)numr);
        long dr = ((long)denr);
        if(nr * dr < 0)
            sign = "-";
        
         nr = abs((long)nr);
         dr = abs((long)dr);
        
        string w = to_string(nr/dr);
        long rem = nr % dr;
        if(rem == 0)
            return sign+w;
        unordered_map<long, long> rec;
        string d = "";
        bool flag = false;
        nr = rem * 10;
        long i = 0;
        while(rec.find(rem) == rec.end())
        {
            rec[rem] = i;
            i++;
            d = d + to_string(nr / dr);
            rem = nr % dr;
            nr = rem * 10;
            if(rem == 0)
            {
                i = rec[rem];
                flag = true;
                break;
            }
            
        }
        
        
        cout << d << endl;
        
        if(flag)
            w = w + "." + d;
        else
        {
            d.insert(rec[rem], "(");
            w = w + "." + d + ")";   
        }
        w = sign + w;
        return w;
    }
};
