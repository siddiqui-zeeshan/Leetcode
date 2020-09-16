class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        //int k;
        //sort(piles.begin(),piles.end());
        int l=1,u=pow(10,9),mid;
        while(l<u)
        {
            mid=l+(u-l)/2;
            int time=0;
            for(int i=0;i<piles.size();i++)
            {
                time=time+(piles[i]-1)/mid+1;
            }
            if(time<=H)
                u=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
