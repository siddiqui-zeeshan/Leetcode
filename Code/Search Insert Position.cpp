class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,u=nums.size()-1;
        int mid;
        while(l<=u)
        {
            mid=l+u;
            mid=mid/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                u=mid-1;
            else
                l=mid+1;
        }
        if(target>nums[mid])
            return mid+1;
        else 
            return mid;
    }
};
