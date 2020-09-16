class Solution {
public:
    struct comparator{
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const{
    return a.first+a.second > b.first+b.second;
  }
};

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty()) return res;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> minHeap;
        
        for(auto n: nums1)
            for(auto m: nums2)
                minHeap.emplace(n, m);
        while(minHeap.size() && k--)
        {
            pair<int, int> pa = minHeap.top();
            res.push_back({pa.first, pa.second});
            minHeap.pop();
        }
        return res;
    }
};
