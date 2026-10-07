class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> heap;
        unordered_map<int,int> freq;
        for(int val : nums) freq[val]++;
        for(auto& [val, count] : freq) {
            heap.push({count, val});
            if(heap.size() > k) {
                heap.pop();
            }
        }
        vector<int> res;
        while(!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
