class Solution {
public:
    int numTeams(vector<int>& A) {
        int count = 0;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = i + 1; j < A.size(); j++)
            {
                for(int k = j + 1; k < A.size(); k++)
                {
                    if(A[i] > A[j] && A[j] > A[k])
                        count++;
                    else if(A[i] < A[j] && A[j] < A[k])
                        count++;
                }
            }
        }
        return count;
    }
};
