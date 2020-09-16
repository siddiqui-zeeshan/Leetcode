class Solution {
public:
    int findComplement(int num) {
        int x=num;
        x=x| (x>>1);
        x=x| (x>>2);
        x=x| (x>>4);
        x=x| (x>>8);
        return x^num;
    }
};
