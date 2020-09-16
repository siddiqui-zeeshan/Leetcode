class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long m = stol(s);
        if(m > INT_MAX)
            return -1;
        return m > n ? m : -1;
    }
};
