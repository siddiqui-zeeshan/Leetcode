class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int l=0;
        int u=nums.size()-1;
        int flag=0;
        if(u==0 && nums[0]==target)
        {
            res.push_back(0);
            res.push_back(0);
            return res;
        }
            
        while(l<=u)
        {
            int mid=l+(u-l)/2;
            if(nums[mid]==target)
            {
                flag++;
                u=mid-1;
            }
            else if(nums[mid]<target)
                l=mid+1;
            else
                u=mid-1;
        }
        if(flag!=0)
            res.push_back(l);
        else
            res.push_back(-1);
        flag=0;
        l=0;
        u=nums.size()-1;
        while(l<=u) { 
            int mid=l+(u-l)/2; 
            if(nums[mid]==target) 
            { 
                flag++; 
                l=mid+1; 
            } 
            else if(nums[mid]<target) 
                l=mid+1; 
            else 
                u=mid-1; 
        }
        if(flag!=0)
        {
          res.push_back(u);
        }
        else
            res.push_back(-1);
        return res;
    }
};
