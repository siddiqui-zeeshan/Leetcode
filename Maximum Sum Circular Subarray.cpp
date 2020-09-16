class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0;
        if(A.size() == 1)
            return A[0];
        for (int i : A) sum += i;
        
        int sum1 = maxSubarraySum(A.begin(), A.end());
        for (int& i : A) i *= -1;
        int sum2 = sum + maxSubarraySum(A.begin(), A.end() - 1);
        int sum3 = sum + maxSubarraySum(A.begin() + 1, A.end());
        return max(sum1, max(sum2, sum3));
    }
    
    int maxSubarraySum(vector<int>::iterator p, vector<int>::iterator q) {
        int result = INT_MIN;
        int f = 0;
        for (auto i = p; i != q; i++) {
            f += *i;
            result = max(result, f);
            if (f < 0) {
                f = 0;
            }
        }
        return result;
    }
};
