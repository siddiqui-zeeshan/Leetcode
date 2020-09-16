class Solution {
public:
    int maxProfit(vector<int>& A) {
        int buy, sell;
        buy = sell = A[0];
        int prof = 0;
        for(int i = 1; i < A.size(); i++)
        {
            if(sell >= A[i])
            {
                prof += sell - buy;
                sell = buy = A[i];
            }
            else
            {
                sell = A[i];
                if(i == A.size() - 1)
                    prof += sell - buy;
            }
            
        }
        return prof;
    }
};
