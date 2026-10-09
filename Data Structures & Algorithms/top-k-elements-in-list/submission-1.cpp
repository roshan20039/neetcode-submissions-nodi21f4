class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>freqgroup[n+1];
        unordered_map<int,int> freq;
        for(int val : nums) freq[val]++;
        for(auto &entry : freq) {
            freqgroup[entry.second].push_back(entry.first);
        }
        vector<int> res;
        for(int i = n; i >0; i--) {
            for(int val : freqgroup[i]) {
                res.push_back(val);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
