class Solution {
public:
    int findLeft(vector<int>& arr, int pos)
    {
        while(pos >= 0 && arr[pos] == -1)
            pos--;
        return pos;
    }
    int findRight(vector<int>& arr, int pos)
    {
        while(pos < arr.size() && arr[pos] == -1)
            pos++;
        pos = pos == arr.size() ? -1 : pos;
        return pos;
    }
    int mctFromLeafValues(vector<int>& arr) {
        multimap<int,int> rec;
        for(int i = 0; i < arr.size(); i++)
            rec.insert({arr[i], i});
        int ans = 0;
        for(auto i : rec)
        {
            //cout<<i.first<<" ";
            int l = findLeft(arr, i.second - 1);
            int r = findRight(arr, i.second + 1);
            //cout<<l<<" "<<r<<endl;
            if(l == -1 && r == -1)
                break;
            if(l == -1)
                ans += i.first * arr[r];
            else if(r == -1)
                ans += i.first * arr[l];
            else
                ans += i.first * min(arr[l], arr[r]);
            arr[i.second] = -1;            
        }
        return ans;
    }
};
