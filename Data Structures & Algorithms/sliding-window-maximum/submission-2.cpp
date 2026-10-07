class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n = nums.size();
        vector<int> res;
        deque<int> q;
        while(j<n){
            while(!q.empty() and nums[q.back()] < nums[j]) {
                q.pop_back();
            }
            q.push_back(j);
            if(i > q.front()) q.pop_front();
            if(j+1 >= k) {
                res.push_back(nums[q.front()]);
                i++;
            }
            j++;
        }
        return res;
    }
};
