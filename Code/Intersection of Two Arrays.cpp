class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set <int> storage;
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++)
        {
            int l=0,u=nums2.size()-1;
            while(l<=u)
            {
                int mid=(l+u)/2;
                if(nums2[mid]==nums1[i])
                {
                    storage.insert(nums2[mid]);
                    break;
                }
                if(nums2[mid]<nums1[i])
                {
                    l=mid+1;
                }
                else if(nums2[mid]>nums1[i])
                {
                    u=mid-1;
                }
            }
        }
        vector <int> output;
        set <int> :: iterator it;
        for(it=storage.begin();it!=storage.end();it++)
        {
            //cout<<*it<<endl;
            output.push_back(*it);
        }
        return output;
    }
};

