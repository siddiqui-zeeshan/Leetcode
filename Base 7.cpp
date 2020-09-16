class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string res = "";
        int sign = num / abs(num);
        int n = abs(num);
        while(n >= 7)
        {
            int d = n % 7;
            res = to_string(d) + res;
            n /= 7;
        }
        res = to_string(n) + res;
        return sign > 0 ? res : "-" + res;
    }
};
