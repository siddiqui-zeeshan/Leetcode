class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,u=nums.size()-1,mid;
        while(l<u)
        {
            mid=l+(u-l)/2;
            if(nums[mid]>nums[mid+1])
                u=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
