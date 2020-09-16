class Solution {
public:
    int findPoisonedDuration(vector<int>& A, int duration) {
        if(A.empty())
            return 0;
        int sum = 0;
        for(int i = 0; i < A.size() - 1; i++)
        {
            sum += min(duration, A[i + 1] - A[i]);
        }
        sum += duration;
        return sum;
    }
};
