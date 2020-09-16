class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int M = k + 1;
        int m = 1;
        vector<int> res;
        int turn = 1;
        while(m <= M)
        {
            if(turn == 1){
                res.push_back(m++);
            }
            else{
                res.push_back(M--);
            }
            turn *= -1;
        }
        m = k + 2;
        while(m <= n)
        {
            res.push_back(m++);
        }
        return res;
    }
};
