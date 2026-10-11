class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> res;
        if(n == 3) {
            if(nums[0] + nums[1] + nums[2] == 0) return {{nums[0], nums[1], nums[2]}};
            else return {};
        }
        while(i<n-2) {
            if(i>0 && nums[i] == nums[i-1]) {
                i++;
                continue;
            }
            int j = i+1, k = n-1;
            while(j < k) {

                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(sum < 0) j++;
                else k--; 
            }
            i++;
        }
        return res;
    }
};
