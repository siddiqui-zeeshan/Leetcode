class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=1;
        int mid=0;
        int u=nums.size()-1;
        if(is_sorted(nums.begin(),nums.end()))
            return nums[0];
        if(nums.size()==2)
            return (nums[0]<nums[1]?nums[0]:nums[1]);
        while(l<u)
        {
            mid=l+(u-l)/2;
            if(nums[mid]>nums[0])
                l=mid+1;
            if(nums[mid]<=nums[0])
                u=mid;
        }
        //if(nums[0]<nums[l])
            //return nums[0];
        return nums[l];
    }
};
