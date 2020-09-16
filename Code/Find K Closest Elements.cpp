class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> rec(arr.size(), 0);
        int m = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            rec[i] = abs(arr[i] - x);
            if(rec[i] < rec[m])
                m = i;
        }
        vector<int> res;
        res.push_back(arr[m]);
        int count = 1;
        int l = m - 1;
        int r = m + 1;
        while(count < k)
        {
            //cout<<l<<" "<<r<<endl;
            if(l >= 0 && r < arr.size() && rec[l] <= rec[r])
            {
                //cout<<"s ";
                res.push_back(arr[l--]);
                count++;
            }
            else if(l >= 0  && r < arr.size() && rec[r] <= rec[l])
            {
                //cout<<"s ";
                res.push_back(arr[r++]);
                count++;
            }
            else if(l < 0 && r < arr.size())
            {
                //cout<<"s ";
                res.push_back(arr[r++]);
                count++;
            }
            else if(r >= arr.size() && l >= 0)
            {
                //cout<<"s ";
                res.push_back(arr[l--]);
                count++;
            }
            else if(l < 0 && r >= arr.size())
            {
                //cout<<"s ";
                break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
