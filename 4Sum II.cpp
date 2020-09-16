class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        vector<int> v;
        //Merge A,B and store result in vector v
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                v.push_back(a[i]+b[j]);
            }
        }
        map<int,int> m;
        //Merge C,D and store count in map m
        for(int i=0;i<c.size();i++){
            for(int j=0;j<d.size();j++){
                m[c[i]+d[j]]++;
            }
        }
        //Iterate over every element in Merged vector and find the number of elements that sum up to zero
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=m[-v[i]];
        }
        return ans;  //return the final answer
    }
};
