class Solution {
public:
    int split(string s, int& y)
    {
        int l = s.length(), i = 1, a;
        while(i < l && s[i] != '+')
            i++;
        a = stoi(s.substr(0,i));
        y = stoi(s.substr(i+1));
        return a;
    }
    string complexNumberMultiply(string a, string b) {
        int x1, y1, x2, y2;
        x1 = x2 = y1 = y2 = 0;
        x1 = split(a, y1);
        x2 = split(b, y2);
        
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
        int t1 = x1 * x2;
        int t2 = -1 * y1 * y2;
        int t3 = x1 * y2 + y1 * x2;
        t1 += t2;
        string res = to_string(t1) + "+" + to_string(t3) + "i";
        return res;
    }
};
