class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long m = n >> 1;
        return ((m + n) & (m + n + 1)) == 0;
    }
};
