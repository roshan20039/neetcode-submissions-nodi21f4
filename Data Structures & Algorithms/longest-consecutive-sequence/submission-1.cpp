class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> numsset(nums.begin(), nums.end());
        int res = 1;
        for(int num : numsset) {
            if(numsset.find(num-1) == numsset.end()) {
                int length = 1;
                while(numsset.find(num+length) != numsset.end()) {
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};
