class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        if(n==0) return 0;
        int l = 0, r = n-1;
        int left_max = height[l];
        int right_max = height[r];
        while(l < r) {
            if(left_max < right_max) {
                l++;
                left_max = max(left_max, height[l]);
                res += left_max-height[l];
            } else {
                r--;
                right_max = max(right_max, height[r]);
                res += right_max - height[r];
            }
        }
    
        return res;  
    }
};

