class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> solution;
        
        for(int i=0;i<numbers.size()-1;i++)
        {
            int l=i+1;
            int u=numbers.size()-1;
            while(l<=u)
            {
                int mid=(l+u)/2;
                if((numbers[i]+numbers[mid])==target)
                {
                    
                    solution.push_back(i+1);
                    solution.push_back(mid+1);
                }
                if((numbers[i]+numbers[mid])>target)
                    u=mid-1;
                else
                    l=mid+1;
            }
        }
        return solution;
    }
};
